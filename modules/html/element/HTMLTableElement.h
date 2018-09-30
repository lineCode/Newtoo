#pragma once

#include "HTMLElement.h"

namespace Newtoo
{

    class HTMLTableCaptionElement;
    class HTMLTableSectionElement;
    class HTMLTableRowElement;

    class HTMLTableElement : public HTMLElement
    {
    public:

        HTMLTableElement();
        HTMLTableElement(DOMString aNamespace, DOMString qualifiedName,DOMString aPrefix = "");

        CSSStyleDeclaration userAgentStyle() override;

        Node* cloneNode(bool deep = false) override;

        HTMLTableCaptionElement* caption();
        HTMLTableCaptionElement createCaption();
        void deleteCaption();

        HTMLTableSectionElement* tHead();
        HTMLTableSectionElement* createTHead();
        void deleteTHead();

        HTMLTableSectionElement* tFoot();
        HTMLTableSectionElement* createTFoot();
        void deleteTFoot();

        HTMLTableSectionElement* createTBody();

        //HTMLCollection tBodies();
        HTMLCollection rows();

        HTMLTableRowElement* insertRow(signed long index = -1);
        void deleteRow(unsigned long index);

        HTMLTableElement(HTMLTableElement& reference, bool deep)
            :HTMLElement(reference, deep)
        {}
    };

}
