#include "PseudoAfterElement.h"

namespace Newtoo
{

    PseudoAfterElement::PseudoAfterElement(Element* aAssignedElement, DOMString aContent,
                                           CSSStyleDeclaration& aStyle)
        :PseudoElement(aAssignedElement)
    {
        aAssignedElement->setPseudoAfter(this);

        for(unsigned i = 0; i < aStyle.length(); i++)
            style().addProperty(aStyle.propertyItem(i));

        setInnerHTML(aContent);

        if(aAssignedElement->parentNode() == 0)
            return;

        aAssignedElement->parentNode()->insertAfter(this, aAssignedElement);
    }

    Node* PseudoAfterElement::cloneNode(bool deep)
    {
        return new PseudoAfterElement(*this, deep);
    }

    bool PseudoAfterElement::isPseudoAfterAssigned()
    {
        return true;
    }

    PseudoAfterElement::~PseudoAfterElement()
    {
        if(assignedElement()->pseudoAfter() == this)
            assignedElement()->setPseudoAfter(0);
    }

}
