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

#define OPEN_COMMENT_STR "/*"
#define CLOSE_COMMENT_STR "*/"
#define OPEN_SINGLE_COMMENT_STR "//"
#define CLOSE_SINGLE_COMMENT_STR "\n"


void eraseComments(DOMString& str)
{
    /*
        Работает довольно медленно. Расчитываю на то,
        что комментариев в коде вообще не будет
    */

    if(str.has(OPEN_COMMENT_STR) or str.has(OPEN_SINGLE_COMMENT_STR))
    {
        while(str.has(OPEN_COMMENT_STR) and str.has(CLOSE_COMMENT_STR))
        {
            unsigned long start = str.indexOf(OPEN_COMMENT_STR);
            unsigned long end = str.indexOf(CLOSE_COMMENT_STR);

            str.eraseThis(start, end - start + 2);
        };
        while(str.has(OPEN_SINGLE_COMMENT_STR) and str.has(CLOSE_SINGLE_COMMENT_STR))
        {
            unsigned long start = str.indexOf(OPEN_SINGLE_COMMENT_STR);
            unsigned long end = str.indexOf(CLOSE_SINGLE_COMMENT_STR);

            str.eraseThis(start, end - start);
        };
    }
}

#define NEWLINE "\n"

    void CSSStyleRule::setCssText(DOMString aCssText)
    {
        eraseComments(aCssText);

        while(aCssText.has(NEWLINE))
            aCssText.eraseThis(aCssText.indexOf(NEWLINE), 1);

        if(!aCssText.has("{"))
            return;

        unsigned long indexOfOpenBracket = aCssText.indexOf("{");

        DOMString selText = aCssText.substring(0, indexOfOpenBracket);
        while(selText.endsWith(" "))
            selText = selText.substring(0, selText.size() - 1);

        setSelectorText(selText);

#ifdef n2DEBUG
        std::cout << "=====================\n" << "[Newtoo::CSSStyleDeclaration Before]: \"" << aCssText.substring(indexOfOpenBracket + 1,
                                                                      aCssText.size() - indexOfOpenBracket - 1).raw() << "\"" << std::endl;
#endif

        style().setCssText(aCssText.substring(indexOfOpenBracket + 1,
                          aCssText.size() - indexOfOpenBracket - 1),
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
