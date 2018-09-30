#include "HTMLBRElement.h"

namespace Newtoo
{

    HTMLBRElement::HTMLBRElement()
    {}

    HTMLBRElement::HTMLBRElement(DOMString aNamespace, DOMString qualifiedName,
                                             DOMString aPrefix)
        :HTMLElement(aNamespace, qualifiedName, aPrefix)
    {}

    CSSStyleDeclaration HTMLBRElement::userAgentStyle()
    {
        CSSStyleDeclaration st;
        st.setProperty("display", "block", UAPropertyPriority);
        return st;
    }

    Node* HTMLBRElement::cloneNode(bool deep)
    {
        return new HTMLBRElement(*this, deep);
    }

}
