#include "HTMLTableRowElement.h"

namespace Newtoo
{

    HTMLTableRowElement::HTMLTableRowElement()
    {}

    HTMLTableRowElement::HTMLTableRowElement(DOMString aNamespace, DOMString qualifiedName,
                                             DOMString aPrefix)
        :HTMLElement(aNamespace, qualifiedName, aPrefix)
    {}

    CSSStyleDeclaration HTMLTableRowElement::userAgentStyle()
    {
        CSSStyleDeclaration st;
        st.setProperty("display", "table-row", UAPropertyPriority);
        return st;
    }

    HTMLCollection HTMLTableRowElement::cells()
    {
        return HTMLCollection(&childNodes(), HTMLCollection::TABLE_CELLS);
    }

    Node* HTMLTableRowElement::cloneNode(bool deep)
    {
        return new HTMLTableRowElement(*this, deep);
    }

}
