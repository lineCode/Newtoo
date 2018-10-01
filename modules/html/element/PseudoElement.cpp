#include "PseudoElement.h"

namespace Newtoo
{

    PseudoElement::PseudoElement()
    {}

    PseudoElement::PseudoElement(DOMString aNamespace, DOMString qualifiedName,
                                             DOMString aPrefix)
        :HTMLElement(aNamespace, qualifiedName, aPrefix)
    {}

    Element* PseudoElement::assignedElement()
    {
        if(isPseudoAfter())
        {
            return previousElementSibling();
        }
        else if(isPseudoBefore())
        {
            return nextElementSibling();
        }
        return 0;
    }

    Node* PseudoElement::cloneNode(bool deep)
    {
        return new PseudoElement(*this, deep);
    }

}
