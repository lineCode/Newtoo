#pragma once

#include "HTMLElement.h"
#include "form/ValidityState.h"

namespace Newtoo
{

    class FileList;
    class HTMLFormElement;

    class HTMLInputElement : public HTMLElement
    {
    public:

        HTMLInputElement();
        HTMLInputElement(DOMString aNamespace, DOMString qualifiedName,DOMString aPrefix = "");

        CSSStyleDeclaration userAgentStyle() override;

        Node* cloneNode(bool deep = false) override;

        DOMString accept()                                  { return getAttribute("accept"); }
        void setAccept(DOMString aAccept)                      { setAttribute("accept", aAccept); }

        DOMString alt()                                     { return getAttribute("alt"); }
        void setAlt(DOMString aAlt)                         { setAttribute("alt", aAlt); }

        DOMString autocapitalize()                          { return getAttribute("autocapitalize"); }
        void setAutocapitalize(DOMString aAutocapitalize)   { setAttribute("autocapitalize", aAutocapitalize); }

        DOMString autocomplete()                            { return getAttribute("autocomplete"); }
        void setAutocomplete(DOMString aAutocomplete)       { setAttribute("autocomplete", aAutocomplete); }

        bool autofocus()                                    { return getAttributeBool("autofocus"); }
        void setAutofocus(bool aAutofocus)                  { setAttributeBool("autofocus", aAutofocus); }

        bool defaultChecked()                               { return getAttributeBool("defaultChecked"); }
        void setDefaultChecked(bool aDefaultChecked)
        { setAttributeBool("defaultChecked", aDefaultChecked); }

        bool checked()                                      { return getAttributeBool("checked"); }
        void setChecked(bool aChecked)                      { setAttributeBool("checked", aChecked); }

        DOMString dirName()                                 { return getAttribute("dirName"); }
        void setDirName(bool aDirName)                      { setAttribute("dirName", aDirName); }

        bool disabled()                                     { return getAttributeBool("disabled"); }
        void setDisabled(bool aDisabled)                    { setAttributeBool("disabled", aDisabled); }

        HTMLFormElement* form();
        FileList* files();

        DOMString formAction()                              { return getAttribute("formAction"); }
        void setFormAction(DOMString aFormAction)           { setAttribute("formAction", aFormAction); }

        DOMString formEnctype()                             { return getAttribute("formEnctype"); }
        void setFormEnctype(DOMString aFormEnctype)         { setAttribute("formEnctype", aFormEnctype); }

        DOMString formMethod()                              { return getAttribute("formMethod"); }
        void setFormMethod(DOMString aFormMethod)           { setAttribute("formMethod", aFormMethod); }

        bool formNoValidate()                               { return getAttributeBool("formNoValidate"); }
        void setFormNoValidate(bool aFormNoValidate)        { setAttributeBool("formNoValidate", aFormNoValidate); }

        DOMString formTarget()                              { return getAttribute("formTarget"); }
        void setFormTarget(DOMString aFormTarget)           { setAttribute("formTarget", aFormTarget); }

        unsigned long height()                              { return getAttributeSignedLong("height"); }
        void setHeight(unsigned long aHeight)               { setAttributeSignedLong("height", aHeight); }

        bool indeterminate()                                { return getAttributeBool("indeterminate"); }
        void setIndeterminate(bool aIndeterminate)          { setAttributeBool("indeterminate", aIndeterminate); }

        HTMLElement* list();

        DOMString max()                                     { return getAttribute("max"); }
        void setMax(DOMString aMax)                         { setAttribute("max", aMax); }

        unsigned long maxLength()                           { return getAttributeSignedLong("maxLength"); }
        void setMaxLength(unsigned long aMaxLength)         { setAttributeSignedLong("maxLength", aMaxLength); }

        DOMString min()                                     { return getAttribute("min"); }
        void setMin(DOMString aMin)                         { setAttribute("min", aMin); }

        unsigned long minLength()                           { return getAttributeSignedLong("minLength"); }
        void setMinLength(unsigned long aMinLength)         { setAttributeSignedLong("minLength", aMinLength); }

        bool multiple()                                     { return getAttributeBool("multiple"); }
        void setMultiple(bool aMultiple)                    { setAttributeBool("multiple", aMultiple); }

        bool readOnly()                                     { return getAttributeBool("ReadOnly"); }
        void setReadOnly(bool aReadOnly)                    { setAttributeBool("ReadOnly", aReadOnly); }

        bool _required()                                    { return getAttributeBool("required"); }
        void set_required(bool a_required)                  { setAttributeBool("required", a_required); }

        DOMString name()                                    { return getAttribute("name"); }
        void setName(DOMString aName)                       { setAttribute("name", aName); }

        DOMString pattern()                                 { return getAttribute("pattern"); }
        void setPattern(DOMString aPattern)                 { setAttribute("pattern", aPattern); }

        DOMString placeholder()                             { return getAttribute("placeholder"); }
        void setPlaceholder(DOMString aPlaceholder)         { setAttribute("placeholder", aPlaceholder); }

        unsigned long size()                                { return getAttributeSignedLong("size"); }
        void setSize(unsigned long aSize)                   { setAttributeSignedLong("size", aSize); }

        DOMString src()                                     { return getAttribute("src"); }
        void setSrc(DOMString aSrc)                       { setAttribute("src", aSrc); }

        DOMString step()                                    { return getAttribute("step"); }
        void setStep(DOMString aStep)                       { setAttribute("step", aStep); }

        DOMString type()                                    { return getAttribute("type"); }
        void setType(DOMString aType)                       { setAttribute("type", aType); }

        DOMString defaultValue()                            { return getAttribute("defaultValue"); }
        void setDefaultValue(DOMString aDefaultValue)       { setAttribute("defaultValue", aDefaultValue); }

        DOMString value()                                   { return getAttribute("value"); }
        void setValue(DOMString aValue)                     { setAttribute("value", aValue); }

        //object? valueAsDate [read]

        double valueAsNumber();

        unsigned long width()                               { return getAttributeSignedLong("width"); }
        void setWidth(unsigned long aWidth)                 { setAttributeSignedLong("width", aWidth); }

        void stepUp(long n = 1);
        void stepDown(long n = 1);

        bool willValidate();
        ValidityState validity();
        DOMString validationMessage();
        bool checkValidity();
        bool reportValidity();
        void setCustomValidity(DOMString error);

        NodeList& labels();

        void select();
        unsigned long setSelectionStart(unsigned long mIndex);
        unsigned long setSelectionEnd(unsigned long mIndex);
        unsigned long selectionStart();
        unsigned long selectionEnd();

        //DOMString? selectionDirection [read & write]

        enum SelectionMode
        {
          Select,
          Start,
          End,
          Preserve
        };

        void setRangeText(DOMString replacement);
        void setRangeText(DOMString replacement, unsigned long start, unsigned long end,
                          SelectionMode selectionMode = Preserve);
        void setSelectionRange(unsigned long start, unsigned long end, DOMString direction);
        void setSelectionRange(unsigned long start, unsigned long end);

        HTMLInputElement(HTMLInputElement& reference, bool deep)
            :HTMLElement(reference, deep),
             mSelectionStart(reference.mSelectionStart),
             mSelectionEnd(reference.mSelectionEnd),
             mSelectionDirection(reference.mSelectionDirection)
        {}

    private:

        unsigned long mSelectionStart, mSelectionEnd;
        DOMString mSelectionDirection;
    };

}
