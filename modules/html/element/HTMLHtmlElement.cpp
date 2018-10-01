#include "HTMLHtmlElement.h"

namespace Newtoo
{

    HTMLHtmlElement::HTMLHtmlElement()
    {}

    HTMLHtmlElement::HTMLHtmlElement(DOMString aNamespace, DOMString qualifiedName,
                                             DOMString aPrefix)
        :HTMLElement(aNamespace, qualifiedName, aPrefix)
    {}

    CSSStyleDeclaration HTMLHtmlElement::userAgentStyle()
    {
        CSSStyleDeclaration st;
        st.setProperty("display", "block", UAPropertyPriority);
        return st;
    }

    Node* HTMLHtmlElement::cloneNode(bool deep)
    {
        return new HTMLHtmlElement(*this, deep);
    }

}
