#pragma once

#include "CSSRule.h"
#include "../style/CSSStyleDeclaration.h"
#include "../../assembly/selector/SelectorRecency.h"
#include "../../assembly/selector/SelectorParser.h"

namespace Newtoo
{

    class CSSStyleRule : public CSSRule
    {
    public:

        CSSStyleRule(DOMString aCssText, CSSRule* parent = 0);

        SelectorRecency& selectorRecency();
        SelectorData& selectorData();
        SelectorString selectorText() const;
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

        SelectorRecency mSelectorRecency;
        SelectorData mSelectorData;
        SelectorString mSelectorText;

        CSSStyleDeclaration mStyle;
        unsigned long mPriority;
    };

}
