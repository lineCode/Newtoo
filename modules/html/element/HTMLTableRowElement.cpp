#include "HTMLTableRowElement.h"
#include "HTMLTableDataCellElement.h"

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

    unsigned long HTMLTableRowElement::rowIndex()
    {
        if(parentElement() == 0)
            return 0;

        HTMLCollection rows = HTMLCollection(&parentElement()->childNodes(), HTMLCollection::TABLE_ROWS);

        for(unsigned i = 0; i < rows.length(); i++)
        {
            if(rows.item(i) == this)
                return i;
        }
        return 0;
    }

    HTMLElement* HTMLTableRowElement::insertCell(signed long index)
    {
        if(index == -1)
        {
            return (HTMLElement*)appendChild((Node*)new HTMLTableDataCellElement());
        } else
        {
            return (HTMLElement*)insertChild((Node*)new HTMLTableDataCellElement(), index);
        }
    }
    void HTMLTableRowElement::deleteCell(unsigned long index)
    {
        removeChild((Node*)HTMLCollection(&childNodes(), HTMLCollection::TABLE_CELLS).item(index));
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
