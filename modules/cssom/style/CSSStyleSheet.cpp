#include "CSSStyleSheet.h"

#include "../../assembly/builder/CSSRuleBuilder.h"

namespace Newtoo
{

    CSSStyleSheet::CSSStyleSheet(CSSRule* aOwnerRule)
        :mOwnerRule(aOwnerRule)
    {}

    StyleSheet* CSSStyleSheet::clone()
    {
        return new CSSStyleSheet(*this);
    }

    const char quote_char = '\"';
    const char alternative_quote = '\'';
    const char close_rule = '}';
    const char close_single_rule = ';';
    const char open_rule = '{';

#define split_target() \
list.push_back(target->substring(i + 1, target->size() - i - 1)); \
target = &list[list.size() - 2]; \
target->eraseThis(i + 1, target->size() - i - 1); \
target = &list.back(); \
size = target->size(); \
i = 0; continue

    std::vector<DOMString> toRuleList(DOMString text)
    {
        std::vector<DOMString> list;
        list.push_back(text);

        DOMString* target = &list[0];

        unsigned long size, level, i;
        size = target->size();
        level = 0;
        i = 0;

        bool inquotes = false;
        char quote = 0;

        while(true)
        {
            if(i >= size)
                break;

            if(!inquotes)
            {
                switch(target->item(i))
                {
                    default:
                    {
                        i++;
                        break;
                    }
                    case open_rule:
                    {
                        level++;
                        i++;
                        break;
                    }
                    case close_rule:
                    {
                        level--;
                        if(level == 0)
                        {
                            split_target();
                        }
                        else i++;
                        break;
                    }
                    case close_single_rule:
                    {
                        if(level == 0)
                        {
                            split_target();
                        }
                        else i++;
                        break;
                    }
                    case quote_char:
                    {
                        inquotes = true;
                        quote = quote_char;
                        i++;
                        break;
                    }
                    case alternative_quote:
                    {
                        inquotes = true;
                        quote = alternative_quote;
                        i++;
                        break;
                    }
                }
            } else
            {
                if(target->item(i) == quote)
                    inquotes = false;
                i++;
            }
        }

#ifdef n2DEBUG
        std::cout << "[REFERENCE]: \n\n\"" << text.raw() << "\n\"\n\n";
        for(unsigned i = 0; i < list.size(); i++)
        {
            std::cout << "[LIST ITEM #" << i <<"]: \n\n\"" << list[i].raw() << "\n\"\n\n";
        }
#endif

        list.pop_back(); // Удалить пустую строку

        return list;
    }

    unsigned long CSSStyleSheet::insertRule(DOMString rule, unsigned long index)
    {
        std::vector<DOMString> rules = toRuleList(rule);

        for(unsigned i = 0; i < rules.size(); i++)
            cssRules().insertRule(CSSRuleBuilder::createRule(rules[i]), index + i);

        return index;
    }

    RaisesExceptionVoid CSSStyleSheet::deleteRule(unsigned long index)
    {
        if(index >= cssRules().length())
            return RaisesExceptionVoid(DOMException(IndexSizeError));

        cssRules().removeRule(index);

        return RaisesExceptionVoid();
    }

    void CSSStyleSheet::appendCSS(DOMString rules)
    {
        std::vector<DOMString> list = toRuleList(rules);

        for(unsigned i = 0; i < list.size(); i++)
            cssRules().appendRule(CSSRuleBuilder::createRule(list[i]));
    }

}
