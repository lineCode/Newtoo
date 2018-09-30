#pragma once

#include "HTMLElement.h"

namespace Newtoo
{

    class HTMLBRElement : public HTMLElement
    {
    public:

        HTMLBRElement();
        HTMLBRElement(DOMString aNamespace, DOMString qualifiedName,DOMString aPrefix = "");

        CSSStyleDeclaration userAgentStyle() override;

        Node* cloneNode(bool deep = false) override;

        HTMLBRElement(HTMLBRElement& reference, bool deep)
            :HTMLElement(reference, deep)
        {}
    };

}
