#include "HTMLTableHeaderCellElement.h"

namespace Newtoo
{

    HTMLTableHeaderCellElement::HTMLTableHeaderCellElement()
    {}

    HTMLTableHeaderCellElement::HTMLTableHeaderCellElement(DOMString aNamespace, DOMString qualifiedName,
                                             DOMString aPrefix)
        :HTMLElement(aNamespace, qualifiedName, aPrefix)
    {}

    CSSStyleDeclaration HTMLTableHeaderCellElement::userAgentStyle()
    {
        CSSStyleDeclaration st;
        st.setProperty("display", "table-cell", UAPropertyPriority);
        st.setProperty("vertical-align", "middle", UAPropertyPriority);
        st.setProperty("font-weight", "bold", UAPropertyPriority);
        st.setProperty("text-align", "center", UAPropertyPriority);
        return st;
    }

    Node* HTMLTableHeaderCellElement::cloneNode(bool deep)
    {
        return new HTMLTableHeaderCellElement(*this, deep);
    }

}
