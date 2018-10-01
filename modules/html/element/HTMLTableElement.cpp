#include "HTMLTableElement.h"
#include "HTMLTableRowElement.h"

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

    HTMLTableRowElement* HTMLTableElement::insertRow(signed long index)
    {
        if(index == -1)
        {
            return (HTMLTableRowElement*)appendChild((Node*)new HTMLTableRowElement());
        } else
        {
            return (HTMLTableRowElement*)insertChild((Node*)new HTMLTableRowElement(), index);
        }
    }
    void HTMLTableElement::deleteRow(unsigned long index)
    {
        removeChild((Node*)HTMLCollection(&childNodes(), HTMLCollection::TABLE_ROWS).item(index));
    }

    Node* HTMLTableElement::cloneNode(bool deep)
    {
        return new HTMLTableElement(*this, deep);
    }

}
