#include "CSSRule.h"
#include "CSSImportRule.h"

namespace Newtoo
{

    CSSRule::CSSRule(RuleType aType, CSSRule* parent)
        :mType(aType), mParentRule(parent)
    {}

#define OPEN_COMMENT_STR "/*"
#define CLOSE_COMMENT_STR "*/"
#define OPEN_SINGLE_COMMENT_STR "//"
#define CLOSE_SINGLE_COMMENT_STR "\n"

#define NEW_LINE "\n"

    CSSRule* CSSRule::clone()
    {
        return new CSSRule(*this);
    }

    DOMString CSSRule::cssText()
    {
        return DOMString("");
    }
    void CSSRule::setCssText(DOMString aCssText)
    {
        aCssText.clear(); // не делать ничего
    }

    CSSStyleSheet* CSSRule::parentStyleSheet()
    {
        if(mParentRule->type() == RuleType::IMPORT_RULE)
        {
            CSSImportRule* i = (CSSImportRule*)mParentRule;
            return &i->styleSheet();
        }

        return 0;
    }

}
