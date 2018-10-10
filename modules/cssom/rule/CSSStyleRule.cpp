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
        DOMString ret = cssComment();
        ret += mSelectorText;
        ret += " { ";
        ret = ret.append_(style().cssText());
        ret += " } ";
        return ret;
    }
    void CSSStyleRule::setCssText(DOMString aCssText)
    {
        CommentCheckOutput commentCheck = checkForComments(aCssText);
        if(commentCheck.hasComments)
        {
            aCssText = commentCheck.processed;
        }

        if(!aCssText.has("{"))
            return;

        unsigned long indexOfOpenBracket = aCssText.indexOf("{");
        // если char равен одному байту

        DOMString selText = aCssText.substring(0, indexOfOpenBracket);
        while(selText.endsWith(" "))
            selText = selText.substring(0, selText.size() - 1);

        setSelectorText(selText);

        style().setCssText(aCssText.substring(indexOfOpenBracket + 1,
                          aCssText.size() - indexOfOpenBracket - 1),
                          std::to_string(mPriority));

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
