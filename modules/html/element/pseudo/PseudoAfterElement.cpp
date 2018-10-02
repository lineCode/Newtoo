#include "PseudoAfterElement.h"

namespace Newtoo
{

    PseudoAfterElement::PseudoAfterElement()
    {}

    PseudoAfterElement::PseudoAfterElement(DOMString aContent, CSSStyleDeclaration& aStyle)
    {
        for(unsigned i = 0; i < aStyle.length(); i++)
            style().addProperty(aStyle.propertyItem(i));

        setInnerHTML(aContent);
    }

    Node* PseudoAfterElement::cloneNode(bool deep)
    {
        return new PseudoAfterElement(*this, deep);
    }

    bool PseudoAfterElement::isPseudoAfterAssigned()
    {
        return true;
    }

}
