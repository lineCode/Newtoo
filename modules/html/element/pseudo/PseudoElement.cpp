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

    void PseudoElement::updatePseudoElement(DOMString aContent, CSSStyleDeclaration& aStyle)
    {
        style().merge(&aStyle);
        setInnerHTML(aContent);
    }

    Node* PseudoElement::cloneNode(bool deep)
    {
        return new PseudoElement(*this, deep);
    }

}
