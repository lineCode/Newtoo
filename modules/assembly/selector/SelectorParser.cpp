#include "SelectorParser.h"
#include "SelectorSyntax.h"
#include "SelectorPseudoClassBuilder.h"

namespace Newtoo
{

    using namespace SelectorSyntax;

    SelectorStringList SelectorParser::groupListFromString(SelectorString string)
    {
        SelectorStringList groups;

        /*
            Сначала, проверим, сколько групп,
            если всего одна, значит вернем
            сразу всю строку.
        */
        char* split = (char*)string.findChar(split_list);

        if(split == 0)
        {
            groups.push_back(string);
            return groups;
        }

        /*
            Убедившись, что групп много,
            нарезаем их по одной группе на
            строку.
        */
        groups.push_back(string);
        DOMString* target = &groups.back();
        split = (char*)target->findChar(split_list);
        do
        {
            unsigned long index = split - target->raw();
            DOMString secondPiece = target->substring(index + 1, target->size() - index - 1);
            *target = target->substring(0, index);
            groups.push_back(secondPiece);
            target = &groups.back();
            split = (char*)target->findChar(split_list);
        }
        while(split != 0);

        return groups;
    }

    enum CompareMode
    {
        Equals,
        Contains,
        ContainsItem,
        StartsWith,
        StartsWithPrefix,
        EndsWith
    };

    enum SwitchCombinator
    {
        NoSwitch,
        Descendant,
        Child,
        NextSibling,
        SubsequentSibling
    };

    SelectorGroup SelectorParser::parseGroupFromString(SelectorString string)
    {
        SelectorGroup group;



        CompareMode compareMode = Equals;
        SwitchCombinator switchCombinator = NoSwitch;
        DOMString content;
        DOMString value2;
        bool inString = false;
        char quote = 0;

        for(signed long i = string.length() - 1; i != -1; i--)
        {
            char c = string[i];

            if(!inString)
            {

                if(c == id)
                {

                    content.clear();
                }
                else if(c == class_char)
                {

                    content.clear();
                }
                else if(c == whitespace)
                {
                    content.clear();

                    if(switchCombinator == NoSwitch)
                        switchCombinator = Descendant;
                }
                else if(c == universal)
                {

                    content.clear();
                }
                else if(c == pseudo_class)
                {
                    SelectorPseudoClassBuilder::appendSelector(group, content);
                    content.clear();
                }
                else if(c == child_combinator)
                {
                    switchCombinator = Child;
                }
                else if(c == next_sibling_combinator)
                {
                    switchCombinator = NextSibling;
                }
                else if(c == subsequent_sibling_combinator)
                {
                    switchCombinator = SubsequentSibling;
                }
                else if(c == compare_equals)
                {
                    compareMode = Equals;
                    value2 = content;
                    content.clear();
                }
                else if(c == compare_starts_with)
                {
                    compareMode = StartsWith;
                }
                else if(c == compare_starts_with_prefix)
                {
                    compareMode = StartsWithPrefix;
                }
                else if(c == compare_ends_with)
                {
                    compareMode = EndsWith;
                }
                else if(c == compare_contains)
                {
                    compareMode = Contains;
                }
                else if(c == compare_contains_item)
                {
                    compareMode = ContainsItem;
                }
                else if(c == compare_close)
                {
                    content.clear();
                }
                else if(c == compare_open)
                {

                    switch(compareMode)
                    {
                        case Equals:
                        {

                            content.clear();
                            break;
                        }
                        case StartsWith:
                        {

                            content.clear();
                            break;
                        }
                        case StartsWithPrefix:
                        {

                            content.clear();
                            break;
                        }
                        case EndsWith:
                        {

                            content.clear();
                            break;
                        }
                        case Contains:
                        {

                            content.clear();
                            break;
                        }
                        case ContainsItem:
                        {

                            content.clear();
                            break;
                        }
                    }
                    content.clear();
                }
                else if(c == quote or c == quote_alternative)
                {
                    quote = c;
                    inString = true;
                }
                else
                {
                    content.prependCharToThis(c);

                    switch(switchCombinator)
                    {
                        case NoSwitch:
                        {
                            break;
                        }
                        case Descendant:
                        {
                            switchCombinator = NoSwitch;


                            break;
                        }
                        case Child:
                        {
                            switchCombinator = NoSwitch;


                            break;
                        }
                        case NextSibling:
                        {
                            switchCombinator = NoSwitch;


                            break;
                        }
                        case SubsequentSibling:
                        {
                            switchCombinator = NoSwitch;


                            break;
                        }
                    }

                    if(i == 0)
                    {
                        //добавить туда TypeSelector
                    }
                }

            } // if(inString)
            else
            {
                if(c == quote)
                {
                    inString = false;
                } else
                {
                    content.prependCharToThis(c);
                }
            }

        }

        return group;
    }

    SelectorData SelectorParser::parseSelectorFromString(SelectorString string)
    {
        SelectorData dat;
        SelectorStringList groupstrlist = groupListFromString(string);

        for(unsigned i = 0; i < groupstrlist.size(); i++)
            dat.groups().push_back(parseGroupFromString(groupstrlist.size()));

        return dat;
    }



}
