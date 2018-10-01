#include "HTMLBodyElement.h"

namespace Newtoo
{

    HTMLBodyElement::HTMLBodyElement()
    {}

    HTMLBodyElement::HTMLBodyElement(DOMString aNamespace, DOMString qualifiedName,
                                             DOMString aPrefix)
        :HTMLElement(aNamespace, qualifiedName, aPrefix)
    {}

    CSSStyleDeclaration HTMLBodyElement::userAgentStyle()
    {
        CSSStyleDeclaration st;
        st.setProperty("display", "block", UAPropertyPriority);
        st.setProperty("box-sizing", "border-box", UAPropertyPriority);
        st.setProperty("margin", "8px", UAPropertyPriority);
        return st;
    }

    Node* HTMLBodyElement::cloneNode(bool deep)
    {
        return new HTMLBodyElement(*this, deep);
    }

}
