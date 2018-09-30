#include "HTMLTableDataCellElement.h"

namespace Newtoo
{

    HTMLTableDataCellElement::HTMLTableDataCellElement()
    {}

    HTMLTableDataCellElement::HTMLTableDataCellElement(DOMString aNamespace, DOMString qualifiedName,
                                             DOMString aPrefix)
        :HTMLElement(aNamespace, qualifiedName, aPrefix)
    {}

    CSSStyleDeclaration HTMLTableDataCellElement::userAgentStyle()
    {
        CSSStyleDeclaration st;
        st.setProperty("display", "table-cell", UAPropertyPriority);
        st.setProperty("vertical-align", "middle", UAPropertyPriority);
        st.setProperty("text-align", "center", UAPropertyPriority);
        return st;
    }

    Node* HTMLTableDataCellElement::cloneNode(bool deep)
    {
        return new HTMLTableDataCellElement(*this, deep);
    }

}
