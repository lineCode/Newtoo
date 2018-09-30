#include "HTMLFormElement.h"

namespace Newtoo
{

    HTMLFormElement::HTMLFormElement()
    {}

    HTMLFormElement::HTMLFormElement(DOMString aNamespace, DOMString qualifiedName,
                                             DOMString aPrefix)
        :HTMLElement(aNamespace, qualifiedName, aPrefix)
    {}

    CSSStyleDeclaration HTMLFormElement::userAgentStyle()
    {
        CSSStyleDeclaration st;
        st.setProperty("display", "block", UAPropertyPriority);
        return st;
    }

    HTMLCollection HTMLFormElement::elements()
    {
        return HTMLCollection(&childNodes(), HTMLCollection::FORM_CONTROLS);
    }

    unsigned long HTMLFormElement::length()
    {
        return elements().length();
    }

    Element* HTMLFormElement::item(unsigned long index)
    {
        return elements().item(index);
    }

    Element* HTMLFormElement::getNamedItem(DOMString name)
    {
        HTMLCollection elms = elements();
        for(unsigned i = 0; i < elms.length(); i++)
        {
            if(elms.item(i)->getAttribute("name") == name)
                return elms.item(i);
        }
        return 0;
    }

    Node* HTMLFormElement::cloneNode(bool deep)
    {
        return new HTMLFormElement(*this, deep);
    }

}
