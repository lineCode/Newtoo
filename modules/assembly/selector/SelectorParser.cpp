#include "SelectorParser.h"
#include "SelectorSyntax.h"
#include "pseudoclass/PseudoClassSelectorBuilder.h"
#include "UniversalSelector.h"
#include "ClassSelector.h"
#include "TypeSelector.h"
#include "IdSelector.h"
#include "combinator/ChildCombinator.h"
#include "combinator/DescedantCombinator.h"
#include "combinator/NextSiblingCombinator.h"
#include "combinator/SubsequentCombinator.h"

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

    void checkForPseudoElement(SelectorGroup group, SelectorString& string)
    {
        if(string.endsWith(FirstletterPseudoElementSuffix))
        {
            group.setMatchesResult(SelectorGroup::Firstletter);

            string = string.substring(0, string.size()
            - sizeof(FirstletterPseudoElementSuffix));
        }

        else if(string.endsWith(FirstlinePseudoElementSuffix))
        {
            group.setMatchesResult(SelectorGroup::Firstline);

            string = string.substring(0, string.size()
            - sizeof(FirstlinePseudoElementSuffix));
        }

        else if(string.endsWith(SelectionPseudoElementSuffix))
        {
            group.setMatchesResult(SelectorGroup::Selection);

            string = string.substring(0, string.size()
            - sizeof(SelectionPseudoElementSuffix));
        }

        else if(string.endsWith(BeforePseudoElementSuffix))
        {
            group.setMatchesResult(SelectorGroup::Before);

            string = string.substring(0, string.size()
            - sizeof(BeforePseudoElementSuffix));
        }

        else if(string.endsWith(AfterPseudoElementSuffix))
        {
            group.setMatchesResult(SelectorGroup::After);

            string = string.substring(0, string.size()
            - sizeof(AfterPseudoElementSuffix));
        }
    }

#define clean_up() if(!query.empty()) { query.clear(); } whitespaceAfter = false

    SelectorGroup SelectorParser::parseGroupFromString(SelectorString string) // bad string
    {
        SelectorGroup group;

        checkForPseudoElement(group, string);

        CompareMode compareMode = Equals;

        DOMString query;
        DOMString value2;
        bool inString = false;
        char quote = 0;

        bool whitespaceAfter = false;

        for(signed long i = string.length() - 1; i != -1; i--)
        {
            char c = string[i];

            if(!inString)
            {

                if(c == id)
                {
                    group.sequence().push_back(IdSelector(query));
                    clean_up();
                }
                else if(c == class_char)
                {
                    group.sequence().push_back(ClassSelector(query));
                    clean_up();
                }
                else if(c == whitespace)
                {
                    if(!query.empty())
                    {
                        group.sequence().push_back(TypeSelector(query));
                        query.clear();
                    }
                    whitespaceAfter = true;
                }
                else if(c == universal)
                {
                    group.sequence().push_back(UniversalSelector());
                    clean_up();
                }
                else if(c == pseudo_class)
                {
                    PseudoClassSelectorBuilder::appendSelector(group, query);
                    clean_up();
                }
                else if(c == child_combinator)
                {
                    group.sequence().push_back(ChildCombinator());
                }
                else if(c == next_sibling_combinator)
                {
                    group.sequence().push_back(NextSiblingCombinator());
                }
                else if(c == subsequent_sibling_combinator)
                {
                    group.sequence().push_back(SubsequentCombinator());
                }
                else if(c == compare_equals)
                {
                    compareMode = Equals;
                    value2 = query;
                    clean_up();
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
                    clean_up();
                }
                else if(c == compare_open)
                {

                    switch(compareMode)
                    {
                        case Equals:
                        {

                            clean_up();
                            break;
                        }
                        case StartsWith:
                        {

                            clean_up();
                            break;
                        }
                        case StartsWithPrefix:
                        {

                            clean_up();
                            break;
                        }
                        case EndsWith:
                        {

                            clean_up();
                            break;
                        }
                        case Contains:
                        {

                            clean_up();
                            break;
                        }
                        case ContainsItem:
                        {

                            clean_up();
                            break;
                        }
                    }
                    clean_up();
                }
                else if(c == quote or c == quote_alternative)
                {
                    quote = c;
                    inString = true;
                }
                else
                {
                    if(whitespaceAfter)
                    {
                        group.sequence().push_back(DescedantCombinator());
                        whitespaceAfter = false;
                    }

                    query.prependCharToThis(c);

                    if(i == 0)
                    {
                        group.sequence().push_back(TypeSelector(query));
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
                    query.prependCharToThis(c);
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
