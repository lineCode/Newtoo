#pragma once

#include "DOMStringOrNull.h"

#include <vector>

namespace Newtoo
{

    const char DatasetWordSplitter = '-';
    const char DatasetPrefix[] = "data-";

    class NamedNodeMap;

    class DOMStringMap
    {
    public:

        DOMStringMap(NamedNodeMap* reference);

        DOMStringOrNull get(DOMString key);
        void set(DOMString key, DOMString value);
        void remove(DOMString key);

        DOMStringOrNull data(DOMString rawKey);
        DOMStringOrNull attr(DOMString attrName);

    private:

        NamedNodeMap* mRef;
    };

}
