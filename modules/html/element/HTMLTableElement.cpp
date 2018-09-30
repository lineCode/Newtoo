#include "HTMLTableElement.h"

namespace Newtoo
{

    HTMLTableElement::HTMLTableElement()
    {}

    HTMLTableElement::HTMLTableElement(DOMString aNamespace, DOMString qualifiedName,
                                             DOMString aPrefix)
        :HTMLElement(aNamespace, qualifiedName, aPrefix)
    {}

    CSSStyleDeclaration HTMLTableElement::userAgentStyle()
    {
        CSSStyleDeclaration st;
        st.setProperty("display", "table", UAPropertyPriority);
        return st;
    }

    HTMLCollection HTMLTableElement::rows()
    {
        return HTMLCollection(&childNodes(), HTMLCollection::TABLE_ROWS);
    }

    Node* HTMLTableElement::cloneNode(bool deep)
    {
        return new HTMLTableElement(*this, deep);
    }

}
