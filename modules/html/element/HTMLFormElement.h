#pragma once

#include "HTMLElement.h"

namespace Newtoo
{

    class HTMLFormElement : public HTMLElement
    {
    public:

        HTMLFormElement();
        HTMLFormElement(DOMString aNamespace, DOMString qualifiedName,DOMString aPrefix = "");

        CSSStyleDeclaration userAgentStyle() override;

        Node* cloneNode(bool deep = false) override;

        DOMString acceptCharset()                           { return getAttribute("acceptCharset"); }
        void setAcceptCharset(DOMString aAcceptCharset)
        { setAttribute("acceptCharset", aAcceptCharset); }

        DOMString action()                                  { return getAttribute("action"); }
        void setAction(DOMString aAction)                   { setAttribute("action", aAction); }

        DOMString autocomplete()                            { return getAttribute("autocomplete"); }
        void setAutocomplete(DOMString aAutocomplete)       { setAttribute("autocomplete", aAutocomplete); }

        DOMString enctype()                                 { return getAttribute("enctype"); }
        void setEnctype(DOMString aEnctype)                 { setAttribute("enctype", aEnctype); }

        DOMString encoding()                                { return getAttribute("encoding"); }
        void setEncoding(DOMString aEncoding)               { setAttribute("encoding", aEncoding); }

        DOMString method()                                  { return getAttribute("method"); }
        void setMethod(DOMString aMethod)                   { setAttribute("method", aMethod); }

        DOMString name()                                    { return getAttribute("name"); }
        void setName(DOMString aName)                       { setAttribute("name", aName); }

        bool noValidate()                                   { return getAttributeBool("noValidate"); }
        void setNoValidate(bool aNoValidate)                { setAttributeBool("noValidate", aNoValidate); }

        DOMString target()                                  { return getAttribute("target"); }
        void setTarget(DOMString aTarget)                   { setAttribute("target", aTarget); }


        /*HTMLFormControlsCollection*/ HTMLCollection elements();

        unsigned long length();

        Element* item(unsigned long index);
        Element* getNamedItem(DOMString name);

        // TODO
        void submit();
        void reset();

        /*
            bool checkValidity();
            bool reportValidity();
        */

        HTMLFormElement(HTMLFormElement& reference, bool deep)
            :HTMLElement(reference, deep)
        {}
    };

}
