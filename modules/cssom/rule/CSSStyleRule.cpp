#include "CSSStyleRule.h"

#include "../../assembly/selector/express/SelectorParserExpress.h"

namespace Newtoo
{

#define WHITESPACE_CHAR ' '

    CSSStyleRule::CSSStyleRule(DOMString aCssText, CSSRule *parent)
        :CSSRule(STYLE_RULE, parent), mPriority(0)
    {
        setCssText(aCssText);
    }

    CSSRule* CSSStyleRule::clone()
    {
        return new CSSStyleRule(*this);
    }

    DOMString CSSStyleRule::cssText()
    {
        DOMString ret = mSelectorText;
        ret += " { ";
        ret = ret.append_(style().cssText());
        ret += " } ";
        return ret;
    }

    const char open_comment[] = "/*";
    const char close_comment[] = "*/";
    const char open_single_comment[] = "//";
    const char close_single_comment[] = "\n";
    const char close_bracket = '}';
    const char open_bracket = '{';
    const char newline = '\n';


    void eraseComments(DOMString& str)
    {
        /*
            Работает довольно медленно. Расчитываю на то,
            что комментариев в коде вообще не будет
        */

        if(str.has(open_comment) or str.has(open_single_comment))
        {
            while(str.has(open_comment) and str.has(close_comment))
            {
                unsigned long start = str.indexOf(open_comment);
                unsigned long end = str.indexOf(close_comment);

                str.eraseThis(start, end - start + 2);
            };
            while(str.has(open_single_comment) and str.has(close_single_comment))
            {
                unsigned long start = str.indexOf(open_single_comment);
                unsigned long end = str.indexOf(close_single_comment);

                str.eraseThis(start, end - start);
            };
        }
    }

    void CSSStyleRule::setCssText(DOMString aCssText)
    {
        eraseComments(aCssText);

        while(aCssText.hasChar(newline))
            aCssText.eraseThis(aCssText.indexOfChar(newline), 1);

        if(!aCssText.hasChar(open_bracket) or !aCssText.hasCharReverse(close_bracket))
            return;

        unsigned long indexOfOpenBracket = aCssText.indexOfChar(open_bracket);
        unsigned long indexOfCloseBracket = aCssText.indexOfChar(close_bracket);

        DOMString selText = aCssText.substring(0, indexOfOpenBracket);
        while(selText.endsWith(" "))
            selText = selText.substring(0, selText.size() - 1);

        setSelectorText(selText);

#ifdef n2DEBUG
        std::cout << "=====================\n" << "[Newtoo::CSSStyleDeclaration Before]: \"" << aCssText.substring(indexOfOpenBracket + 1,
                                                                      indexOfCloseBracket - indexOfOpenBracket - 1).raw() << "\"" << std::endl;
#endif

        style().setCssText(aCssText.substring(indexOfOpenBracket + 1,
                          indexOfCloseBracket - indexOfOpenBracket - 1),
                          std::to_string(mPriority));

#ifdef n2DEBUG
        std::cout << "-----\n" << "[Newtoo::CSSStyleDeclaration After]: \"" << style().cssText().raw() << "\"" << std::endl;
#endif

    }

    SelectorRecency& CSSStyleRule::selectorRecency()
    {
        return mSelectorRecency;
    }

    SelectorData& CSSStyleRule::selectorData()
    {
        return mSelectorData;
    }

    SelectorString CSSStyleRule::selectorText() const
    {
        return mSelectorText;
    }

    void CSSStyleRule::setSelectorText(DOMString aText)
    {
        while(aText.startsWithChar(WHITESPACE_CHAR))
            aText = aText.substring(1, aText.size() - 1);

        if(aText == mSelectorText)
            return;

        mSelectorText = aText;

        mSelectorData = SelectorParser::parseSelectorFromString(mSelectorText);

        mSelectorData.calcPriority();
        mPriority = mSelectorData.priority();

        mSelectorRecency.renew();
    }

}
