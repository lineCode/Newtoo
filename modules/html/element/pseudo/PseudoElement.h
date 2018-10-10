#pragma once

#include "../HTMLElement.h"

namespace Newtoo
{

    const char pseudoBefore[] = "::before";
    const char pseudoAfter[] = "::after";

    class PseudoElement : public HTMLElement
    {
    public:

        PseudoElement(Element* aAssingedElement);

        Node* cloneNode(bool deep = false) override;

        DOMString nodeValue() override;

        Element* assignedElement() const;

        PseudoElement(PseudoElement& reference, bool deep)
            :HTMLElement(reference, deep)
        {}

    private:

        Element* mAssinged;
    };

}
