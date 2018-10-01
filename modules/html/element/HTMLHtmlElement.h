#pragma once

#include "HTMLElement.h"

namespace Newtoo
{

    class HTMLHtmlElement : public HTMLElement
    {
    public:

        HTMLHtmlElement();
        HTMLHtmlElement(DOMString aNamespace, DOMString qualifiedName,DOMString aPrefix = "");

        CSSStyleDeclaration userAgentStyle() override;

        Node* cloneNode(bool deep = false) override;

        HTMLHtmlElement(HTMLHtmlElement& reference, bool deep)
            :HTMLElement(reference, deep)
        {}
    };

}
