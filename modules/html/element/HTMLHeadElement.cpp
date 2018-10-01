#include "HTMLHeadElement.h"

namespace Newtoo
{

    HTMLHeadElement::HTMLHeadElement()
    {}

    HTMLHeadElement::HTMLHeadElement(DOMString aNamespace, DOMString qualifiedName,
                                             DOMString aPrefix)
        :HTMLElement(aNamespace, qualifiedName, aPrefix)
    {}

    CSSStyleDeclaration HTMLHeadElement::userAgentStyle()
    {
        CSSStyleDeclaration st;
        st.setProperty("display", "none", UAPropertyPriority);
        return st;
    }

    Node* HTMLHeadElement::cloneNode(bool deep)
    {
        return new HTMLHeadElement(*this, deep);
    }

}
