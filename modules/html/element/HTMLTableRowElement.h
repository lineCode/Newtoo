#pragma once

#include "HTMLElement.h"

namespace Newtoo
{

    class HTMLTableRowElement : public HTMLElement
    {
    public:

        HTMLTableRowElement();
        HTMLTableRowElement(DOMString aNamespace, DOMString qualifiedName,DOMString aPrefix = "");

        CSSStyleDeclaration userAgentStyle() override;

        Node* cloneNode(bool deep = false) override;

        unsigned long rowIndex();
        unsigned long sectionRowIndex();

        HTMLCollection cells();

        HTMLElement* insertCell(signed long index = -1);
        void deleteCell(unsigned long index);

        HTMLTableRowElement(HTMLTableRowElement& reference, bool deep)
            :HTMLElement(reference, deep)
        {}
    };

}
