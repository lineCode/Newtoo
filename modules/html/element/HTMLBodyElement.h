#pragma once

#include "HTMLElement.h"

namespace Newtoo
{

    class HTMLBodyElement : public HTMLElement
    {
    public:

        HTMLBodyElement();
        HTMLBodyElement(DOMString aNamespace, DOMString qualifiedName,DOMString aPrefix = "");

        CSSStyleDeclaration userAgentStyle() override;

        Node* cloneNode(bool deep = false) override;

        HTMLBodyElement(HTMLBodyElement& reference, bool deep)
            :HTMLElement(reference, deep)
        {}
    };

}
