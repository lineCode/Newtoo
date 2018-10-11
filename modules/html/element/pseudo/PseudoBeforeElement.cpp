#include "PseudoBeforeElement.h"

namespace Newtoo
{

    PseudoBeforeElement::PseudoBeforeElement(Element* aAssignedElement, DOMString aContent,
                                             CSSStyleDeclaration& aStyle)
        :PseudoElement(aAssignedElement)
    {
        aAssignedElement->setPseudoBefore(this);

        for(unsigned i = 0; i < aStyle.length(); i++)
            style().addProperty(aStyle.propertyItem(i));

        setInnerHTML(aContent);

        if(aAssignedElement->parentNode() == 0)
            return;

        aAssignedElement->parentNode()->insertBefore(this, aAssignedElement);
    }

    Node* PseudoBeforeElement::cloneNode(bool deep)
    {
        return new PseudoBeforeElement(*this, deep);
    }

    bool PseudoBeforeElement::isPseudoBeforeAssigned()
    {
        return true;
    }

    PseudoBeforeElement::~PseudoBeforeElement()
    {
        if(assignedElement()->pseudoBefore() == this)
            assignedElement()->setPseudoBefore(0);
    }

}
