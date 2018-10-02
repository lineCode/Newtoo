#pragma once

#include "HTMLElement.h"

namespace Newtoo
{

    const char pseudoBefore[] = "::before";
    const char pseudoAfter[] = "::after";

    class PseudoElement : public HTMLElement
    {
    public:

        PseudoElement();
        PseudoElement(DOMString aNamespace, DOMString qualifiedName,DOMString aPrefix = "");

        Node* cloneNode(bool deep = false) override;

        DOMString nodeValue() override;

        Element* assignedElement();

        PseudoElement(PseudoElement& reference, bool deep)
            :HTMLElement(reference, deep)
        {}
    };

}
