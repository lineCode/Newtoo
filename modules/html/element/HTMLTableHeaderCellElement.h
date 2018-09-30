#pragma once

#include "HTMLElement.h"

namespace Newtoo
{

    class HTMLTableHeaderCellElement : public HTMLElement
    {
    public:

        HTMLTableHeaderCellElement();
        HTMLTableHeaderCellElement(DOMString aNamespace, DOMString qualifiedName,DOMString aPrefix = "");

        CSSStyleDeclaration userAgentStyle() override;

        Node* cloneNode(bool deep = false) override;

        HTMLTableHeaderCellElement(HTMLTableHeaderCellElement& reference, bool deep)
            :HTMLElement(reference, deep)
        {}
    };

}
