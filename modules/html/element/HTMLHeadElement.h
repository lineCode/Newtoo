#pragma once

#include "HTMLElement.h"

namespace Newtoo
{

    class HTMLHeadElement : public HTMLElement
    {
    public:

        HTMLHeadElement();
        HTMLHeadElement(DOMString aNamespace, DOMString qualifiedName,DOMString aPrefix = "");

        CSSStyleDeclaration userAgentStyle() override;

        Node* cloneNode(bool deep = false) override;

        HTMLHeadElement(HTMLHeadElement& reference, bool deep)
            :HTMLElement(reference, deep)
        {}
    };

}
