#include "DOMStringMap.h"

#include "../../dom/node/container/NamedNodeMap.h"
#include "../../dom/node/Document.h"

namespace Newtoo
{

    DOMStringMap::DOMStringMap(NamedNodeMap* reference)
        :mRef(reference)
    {}

    DOMString toKebabCase(DOMString& lowerCamelCaseString)
    {
        std::string c = lowerCamelCaseString.raw();
        unsigned i = 0;
        while(true)
        {
            if(i >= c.size())
                break;

            if(isupper(c[i]))
            {
                char lower = tolower(c[i]);
                std::string next = c.substr(i + 1, c.size() - i - 1);
                c = c.substr(0, i);
                c = c + DatasetWordSplitter;
                c = c + lower;
                c = c + next;
            }
            i++;
        }
        return DOMString(c);
    }

    DOMString withPrefix(DOMString& key)
    {
        DOMString prefixed = DatasetPrefix;
        prefixed += toKebabCase(key);
        return prefixed;
    }
    DOMString withOnlyPrefix(DOMString& key)
    {
        DOMString prefixed = DatasetPrefix;
        prefixed += key;
        return prefixed;
    }

    DOMStringOrNull DOMStringMap::get(DOMString key)
    {
        return attr(withPrefix(key));
    }

    void DOMStringMap::set(DOMString key, DOMString value)
    {
        Attr* attr = Document::createAttribute(withPrefix(key));
        attr->setValue(value);
        mRef->setNamedItem(attr);
    }

    void DOMStringMap::remove(DOMString key)
    {
        mRef->removeNamedItem(withPrefix(key));
    }

    DOMStringOrNull DOMStringMap::data(DOMString rawKey)
    {
        return attr(withOnlyPrefix(rawKey));
    }

    DOMStringOrNull DOMStringMap::attr(DOMString attrName)
    {
        RaisesException<Attr*> attr = mRef->getNamedItem(attrName);
        if(!attr.hasException())
        {
            return DOMStringOrNull(attr.returnType()->value());
        } else
        {
            return DOMStringOrNull();
        }
    }

}
