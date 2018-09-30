#pragma once

#include "HTMLElement.h"

namespace Newtoo
{

    class HTMLTableDataCellElement : public HTMLElement
    {
    public:

        HTMLTableDataCellElement();
        HTMLTableDataCellElement(DOMString aNamespace, DOMString qualifiedName,DOMString aPrefix = "");

        CSSStyleDeclaration userAgentStyle() override;

        Node* cloneNode(bool deep = false) override;

        HTMLTableDataCellElement(HTMLTableDataCellElement& reference, bool deep)
            :HTMLElement(reference, deep)
        {}
    };

}
