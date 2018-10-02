#pragma once

#include "PseudoElement.h"

namespace Newtoo
{

    class PseudoAfterElement : public PseudoElement
    {
    public:

        PseudoAfterElement();
        PseudoAfterElement(DOMString aContent, CSSStyleDeclaration& aStyle);

        Node* cloneNode(bool deep = false) override;

        bool isPseudoAfterAssigned();

        PseudoAfterElement(PseudoAfterElement& reference, bool deep)
            :PseudoElement(reference, deep)
        {}
    };

}
