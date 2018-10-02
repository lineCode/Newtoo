#pragma once

#include "CSSRule.h"
#include "../style/CSSStyleDeclaration.h"

namespace Newtoo
{

    class CSSStyleRule : public CSSRule
    {
    public:

        CSSStyleRule(DOMString aCssText, CSSRule* parent = 0);

        DOMString selectorText() const                          { return mSelectorText; }
        void setSelectorText(DOMString aText);

        CSSStyleDeclaration& style()                            { return mStyle; }

        unsigned long priority()                          const { return mPriority; }

        CSSRule* clone() override;

        DOMString cssText() override;
        void setCssText(DOMString aCssText) override;

        CSSStyleRule(CSSStyleRule& reference)
            :CSSRule(reference),
             mSelectorText(reference.mSelectorText),
             mStyle(reference.mStyle, this),
             mPriority(reference.mPriority)
        {}

    private:

        DOMString mSelectorText;
        CSSStyleDeclaration mStyle;
        unsigned long mPriority;
    };

}
