#include "Element.h"
#include "Text.h"
#include "Document.h"
#include "../../styling/misc/StyleAssembler.h"
#include "../../assembly/selector/express/SelectorParserExpress.h"
#include "../../assembly/html/HTMLSerializer.h"
#include "../../assembly/html/HTMLParser.h"
#include "../../html/element/pseudo/PseudoElement.h"

namespace Newtoo
{

    Element::Element() : mPseudoBefore(0), mPseudoAfter(0) {}

    Element::Element(DOMString aLocalName)
        :Node(ELEMENT_NODE),
         mLocalName(aLocalName), mPseudoBefore(0), mPseudoAfter(0)
    {}

    Element::Element(DOMString aNamespace, DOMString qualifiedName, DOMString aPrefix)
        :Node(ELEMENT_NODE),
         mNamespaceURI(aNamespace),
         mPrefix(aPrefix),
         mLocalName(qualifiedName),
         mPseudoBefore(0),
         mPseudoAfter(0)
    {}

#define AFTER_PREFIX ":"

    DOMString Element::tagName()
    {
        DOMString full;
        if(!mPrefix.empty())
        {
            full += mPrefix;
            full += AFTER_PREFIX;
        }
        full += mLocalName;
        return full;
    }

    Node* Element::cloneNode(bool deep)
    {
        return new Element(*this, deep);
    }

    DOMString Element::nodeName()
    {
        return tagName();
    }

    void findText(NodeList& list, DOMString& str)
    {
        for(unsigned i = 0; i < list.length(); i++)
        {
            if(list.item(i)->hasTextValue())
                str = str.append_(list.item(i)->nodeValue());
            else
                findText(list.item(i)->childNodes(), str);
        }
    }

    DOMString Element::textContent()
    {
        DOMString ret;
        findText(childNodes(), ret);
        return ret;
    }

    void Element::setTextContent(DOMString aPlainText)
    {
        for(unsigned i = 0; i < childNodes().length(); i++)
            childNodes().item(i)->remove();

        appendChild(new Text(aPlainText));
    }

    DOMTokenList Element::reflectTo(DOMString attrName)
    {
        Attr* attr = getAttributeNode(attrName);
        if(attr != 0)
            return DOMTokenList(attr->valueRaw());
        else
            return DOMTokenList(0);
    }
    DOMStringMap Element::reflectToAttributes()
    {
        return DOMStringMap(&mAttributes);
    }

    Attr* Element::getAttributeNode(DOMString qualifiedName)
    {
        RaisesException<Attr*> ret = mAttributes.getNamedItem(qualifiedName);

        if(ret.hasException())
            return 0;
        else
            return ret.returnType();
    }
    Attr* Element::getAttributeNodeNS(DOMString aNamespace, DOMString localName)
    {
        RaisesException<Attr*> ret = mAttributes.getNamedItemNS(aNamespace, localName);

        if(ret.hasException())
            return 0;
        else
            return ret.returnType();
    }

    DOMString Element::getAttribute(DOMString qualifiedName)
    {
        RaisesException<Attr*> a = mAttributes.getNamedItem(qualifiedName);

        if(!a.hasException())
            return a.returnType()->value();

        return DOMString("");
    }
    DOMString Element::getAttributeNS(DOMString aNamespace, DOMString localName)
    {
        RaisesException<Attr*> a = mAttributes.getNamedItemNS(aNamespace, localName);

        if(!a.hasException())
            return a.returnType()->value();

        return DOMString("");
    }

    void Element::setAttribute(DOMString qualifiedName, DOMString value)
    {
        mAttributes.setNamedItem(new Attr(qualifiedName, value, this));
    }
    void Element::setAttributeNS(DOMString aNamespace, DOMString qualifiedName, DOMString value)
    {
        mAttributes.setNamedItemNS(new Attr(aNamespace, qualifiedName, value, this));
    }

    void Element::removeAttribute(DOMString qualifiedName)
    {
        mAttributes.removeNamedItem(qualifiedName);
    }
    void Element::removeAttributeNS(DOMString aNamespace, DOMString localName)
    {
        mAttributes.removeNamedItemNS(aNamespace, localName);
    }

    bool Element::hasAttribute(DOMString qualifiedName)
    {
        return !mAttributes.getNamedItem(qualifiedName).hasException();
    }
    bool Element::hasAttributeNS(DOMString aNamespace, DOMString localName)
    {
        return !mAttributes.getNamedItemNS(aNamespace, localName).hasException();
    }

    Element* Element::previousElementSibling()
    {
        if(parentNode() == 0)
            return 0;

        unsigned long ind = collectionIndex();

        if(ind == 0)
            return 0;

        else return parentNode()->children().item(ind - 1);
    }
    Element* Element::nextElementSibling()
    {
        if(parentNode() == 0)
            return 0;

        else return parentNode()->children().item(collectionIndex() + 1);
    }

    bool Element::hasAttributes()
    {
        return false;//!mAttributes.empty();
    }

    bool Element::matches(DOMString selectors)
    {
        return SelectorParserExpress::elementMatches(this, selectors)
                != SelectorParserExpress::NotMatches;
    }

    HTMLCollection Element::getElementsByTagName(DOMString localName)
    {
        return HTMLCollection(&mChildNodes, HTMLCollection::BY_TAG_NAME, localName);
    }
    HTMLCollection Element::getElementsByTagNameNS(DOMString aNamespace, DOMString localName)
    {
        return HTMLCollection(&mChildNodes, HTMLCollection::BY_TAG_NAME_NS, aNamespace, localName);
    }
    HTMLCollection Element::getElementsByClassName(DOMString classNames)
    {
        return HTMLCollection(&mChildNodes, HTMLCollection::BY_CLASS_NAME, classNames);
    }

    void findElementById(Element* p, DOMString aId, NodeList& list)
    {
        for(unsigned i = 0; i < list.length(); i++)
        {
            if(list.item(i)->nodeType() == Node::ELEMENT_NODE)
            {
                Element* elm = (Element*)list.item(i);

                if(elm->id() == aId)
                {
                    p = elm;
                }
                else findElementById(p, aId, elm->childNodes());
            }
        }
    }

    Element* Element::getElementById(DOMString aId)
    {
        Element* ret = 0;
        findElementById(ret, aId, childNodes());
        return ret;
    }

    unsigned long Element::collectionIndex()
    {
        HTMLCollection parentChilds = parentElement()->children();
        for(unsigned i = 0; i < parentChilds.length(); i++)
        {
            if(parentChilds.item(i) == this)
                return i;
        }
        return 0;
    }

    DOMString Element::innerHTML()
    {
        HTMLSerializerNodeSequence sequence;

        for(unsigned i = 0; i < childNodes().length(); i++)
            sequence.push_back(childNodes().item(i));

        return HTMLSerializer::serializeToString(sequence);
    }
    void Element::setInnerHTML(DOMString aHTML)
    {
        while(!childNodes().empty())
            removeChild(childNodes().item(0));

        HTMLParserOutput newChilds = HTMLParser::parseHtmlFromString(aHTML);
        for(unsigned i = 0; i < newChilds.size(); i++)
            appendChild(newChilds[i]);
    }

    DOMString Element::outerHTML()
    {
        HTMLSerializerNodeSequence sequence;
        sequence.push_back(this);

        return HTMLSerializer::serializeToString(sequence);
    }
    void Element::setOuterHTML(DOMString aHTML)
    {
        unsigned long ind = index();
        Node* parent = parentNode();

        if(parent == 0)
            return;

        remove();

        HTMLParserOutput list = HTMLParser::parseHtmlFromString(aHTML);

        for(unsigned i = 0; i < list.size(); i++)
            parent->insertChild(list[i], ind + i);
    }

    Element::ElementKind Element::getElementKind()
    {
        return ElementKind::Element;
    }

    bool Element::isFormControl()
    {
        return false;
    }

    bool Element::isTableCell()
    {
        return (localName() == "td" or localName() == "th") ? true : false;
    }
    bool Element::isTableRow()
    {
        return (localName() == "tr") ? true : false;
    }

    bool Element::isHTMLElement()
    {
        return getElementKind() == ElementKind::HTMLElement;
    }
    bool Element::isSVGElement()
    {
        return getElementKind() == ElementKind::SVGElement;
    }

    bool Element::isPseudoElement()
    {
        return isPseudoBeforeAssigned() or isPseudoAfterAssigned();
    }

    PseudoElement* Element::pseudoBefore() const
    {
        return (PseudoElement*)mPseudoBefore;
    }
    PseudoElement* Element::pseudoAfter() const
    {
        return (PseudoElement*)mPseudoAfter;
    }

    bool Element::hasPseudoBefore()
    {
        return mPseudoBefore;
    }
    bool Element::hasPseudoAfter()
    {
        return mPseudoAfter;
    }

    void Element::setPseudoBefore(Element* aElement)
    {
        mPseudoBefore = aElement;
    }
    void Element::setPseudoAfter(Element* aElement)
    {
        mPseudoAfter = aElement;
    }

    void Element::setAttributeBool(DOMString qualifiedName, bool value)
    {
        DOMString arg = value ? "true" : "false";

        setAttribute(qualifiedName, arg);
    }
    bool Element::getAttributeBool(DOMString qualifiedName)
    {
        return getAttribute(qualifiedName) == "true" ? true : false;
    }
    void Element::setAttributeSignedLong(DOMString qualifiedName, signed long value)
    {
        DOMString arg;
        arg.fromInt(value);

        setAttribute(qualifiedName, arg);
    }
    signed long Element::getAttributeSignedLong(DOMString qualifiedName)
    {
        return getAttribute(qualifiedName).toInt();
    }

    CSSStyleDeclaration Element::userAgentStyle()
    {
        return CSSStyleDeclaration();
    }

    CSSStyleDeclaration* Element::parentStyle()
    {
        if(parentElement() == 0)
            return 0;

        return &parentElement()->style();
    }

    void Element::cascadeStyles()
    {
        Document* doc = ownerDocument();
        if(doc == 0)
            return;

        StyleAssembler::cascade((Element*)this, (StyleSheetListReflect&)ownerDocument()->styleSheets());
    }

    Element::~Element()
    {
        if(pseudoBefore() != 0)
            pseudoBefore()->remove();

        if(pseudoAfter() != 0)
            pseudoAfter()->remove();
    }

}
