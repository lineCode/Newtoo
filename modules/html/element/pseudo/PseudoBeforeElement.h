#pragma once

#include "PseudoElement.h"

namespace Newtoo
{

    class PseudoBeforeElement : public PseudoElement
    {
    public:

        PseudoBeforeElement();
        PseudoBeforeElement(DOMString aContent, CSSStyleDeclaration& aStyle);

        Node* cloneNode(bool deep = false) override;

        bool isPseudoBeforeAssigned();

        PseudoBeforeElement(PseudoBeforeElement& reference, bool deep)
            :PseudoElement(reference, deep)
        {}
    };

}
