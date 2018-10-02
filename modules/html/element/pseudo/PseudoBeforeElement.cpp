#include "PseudoBeforeElement.h"

namespace Newtoo
{

    PseudoBeforeElement::PseudoBeforeElement()
    {}

    PseudoBeforeElement::PseudoBeforeElement(DOMString aContent, CSSStyleDeclaration& aStyle)
    {
        for(unsigned i = 0; i < aStyle.length(); i++)
            style().addProperty(aStyle.propertyItem(i));

        setInnerHTML(aContent);
    }

    Node* PseudoBeforeElement::cloneNode(bool deep)
    {
        return new PseudoBeforeElement(*this, deep);
    }

    bool PseudoBeforeElement::isPseudoBeforeAssigned()
    {
        return true;
    }

}
