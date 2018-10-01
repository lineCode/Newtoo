#include "HTMLInputElement.h"

namespace Newtoo
{

    HTMLInputElement::HTMLInputElement() : mSelectionStart(0), mSelectionEnd(0)
    {}

    HTMLInputElement::HTMLInputElement(DOMString aNamespace, DOMString qualifiedName,
                                             DOMString aPrefix)
        :HTMLElement(aNamespace, qualifiedName, aPrefix),
          mSelectionStart(0), mSelectionEnd(0)
    {}

    CSSStyleDeclaration HTMLInputElement::userAgentStyle()
    {
        CSSStyleDeclaration st;
        st.setProperty("background-color", "#ffffff", UAPropertyPriority);
        st.setProperty("border", "2px solid #707070", UAPropertyPriority);
        st.setProperty("color", "#212121", UAPropertyPriority);
        st.setProperty("display", "inline-block", UAPropertyPriority);
        st.setProperty("font-family", "\"Arial\"", UAPropertyPriority);
        st.setProperty("padding-bottom", "1px", UAPropertyPriority);
        st.setProperty("padding-top", "1px", UAPropertyPriority);
        st.setProperty("white-space", "pre", UAPropertyPriority);
        return st;
    }

    Node* HTMLInputElement::cloneNode(bool deep)
    {
        return new HTMLInputElement(*this, deep);
    }

}
