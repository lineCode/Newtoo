#include "PseudoElement.h"

namespace Newtoo
{

    PseudoElement::PseudoElement(Element* aAssingedElement)
        :mAssinged(aAssingedElement)
    {}

    DOMString PseudoElement::nodeValue()
    {
        return localName();
    }

    Element* PseudoElement::assignedElement() const
    {
        return mAssinged;
    }

    Node* PseudoElement::cloneNode(bool deep)
    {
        return new PseudoElement(*this, deep);
    }

}
