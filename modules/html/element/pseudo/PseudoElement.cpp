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
        style().clear();

        for(unsigned i = 0; i < aStyle.length(); i++)
            style().addProperty(aStyle.propertyItem(i));

        setInnerHTML(aContent);
    }

    Node* PseudoElement::cloneNode(bool deep)
    {
        return new PseudoElement(*this, deep);
    }

}
