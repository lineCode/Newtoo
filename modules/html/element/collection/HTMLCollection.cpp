#include "HTMLCollection.h"
#include "../../../dom/node/Element.h"

namespace Newtoo
{

    HTMLCollection::HTMLCollection(NodeList* aNodeList, Mode aMode, DOMString aArg, DOMString aArg2)
        :mArg(aArg), mArg2(aArg2), mMode(aMode), mNodeListRef(aNodeList)
    {}

    void lengthRecursive(unsigned long& len, HTMLCollection& collection, NodeList* target)
    {
        for(unsigned i = 0; i < target->length(); i++)
        {
            if(target->item(i)->nodeType() == Node::ELEMENT_NODE)
            {
                Element* elm = (Element*)target->item(i);

                if(collection.acceptToCollection(elm))
                {
                    len++;
                }
                lengthRecursive(len, collection, &elm->childNodes());
            }
        }
    }

    unsigned long HTMLCollection::length()
    {
        unsigned long ret = 0;
        lengthRecursive(ret, *this, mNodeListRef);
        return ret;
    }

    bool HTMLCollection::acceptToCollection(Element* childElement)
    {
        bool accept = true;
        switch(mMode)
        {
            case NORMAL:
                break;

            case BY_CLASS_NAME:
            {
                if(childElement->className() != mArg)
                    accept = false;
                break;
            }
            case BY_TAG_NAME:
            {
                if(childElement->localName() != mArg)
                    accept = false;
                break;
            }
            case BY_TAG_NAME_NS:
            {
            if(childElement->namespaceURI() != mArg or childElement->localName() != mArg2)
                accept = false;
                break;
            }
            case BY_NAME:
            {
                Attr* nameAttr = childElement->getAttributeNode("name");

                if(nameAttr->value() != mArg or nameAttr == 0)
                    accept = false;
                break;
            }
            case IMAGES:
            {
                if(childElement->localName() != "image" or childElement->localName() != "img")
                    accept = false;
                break;
            }
            case EMBEDS:
            {
                if(childElement->localName() != "embed")
                    accept = false;
                break;
            }
            case LINKS:
            {
                if(childElement->localName() != "a")
                    accept = false;
                break;
            }
            case FORMS:
            {
                if(childElement->localName() != "form")
                    accept = false;
                break;
            }
            case SCRIPTS:
            {
                if(childElement->localName() != "script")
                    accept = false;
                break;
            }
            case FORM_CONTROLS:
            {
                if(!childElement->isFormControl())
                    accept = false;
                break;
            }
            case TABLE_CELLS:
            {
                if(childElement->parentNode() != (Node*)this or !childElement->isTableCell())
                    accept = false;
                break;
            }
            case TABLE_ROWS:
            {
                if(childElement->parentNode() != (Node*)this or !childElement->isTableRow())
                    accept = false;
                break;
            }
        }
        return accept;
    }

    void itemRecursive(Element* elm, unsigned long index, unsigned long& in, HTMLCollection& collection,
                       NodeList* target)
    {
        if(elm != 0)
            return;

        for(unsigned i = 0; i < target->length(); i++)
        {
            Node* child = target->item(i);

            if(child->nodeType() == Node::ELEMENT_NODE)
            {
                Element* childElement = (Element*)child;

                if(collection.acceptToCollection(childElement))
                {
                    if(index == in)
                        elm = childElement;
                    in++;
                }
                itemRecursive(elm, index, in, collection, &childElement->childNodes());
            }
        }
    }

    void namedItemRecursive(Element* elm, DOMString name, HTMLCollection& collection, NodeList* target)
    {
        if(elm != 0)
            return;

        for(unsigned i = 0; i < target->length(); i++)
        {
            Node* child = target->item(i);

            if(child->nodeType() == Node::ELEMENT_NODE)
            {
                Element* childElement = (Element*)child;
                if(collection.acceptToCollection(childElement) and childElement->id() == name)
                {
                    elm = childElement;
                }
                namedItemRecursive(elm, name, collection, &childElement->childNodes());
            }
        }
    }

    Element* HTMLCollection::item(unsigned long index)
    {
        if(index < length())
        {
            Element* ret = 0;
            unsigned long in = 0;
            itemRecursive(ret, index, in, *this, mNodeListRef);
            return ret;
        }
        else return 0;
    }
    Element* HTMLCollection::namedItem(DOMString name)
    {
        Element* ret = 0;
        namedItemRecursive(ret, name, *this, mNodeListRef);
        return 0;
    }

}
