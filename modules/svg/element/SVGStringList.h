#pragma once

#include "../../dom/DOMString.h"
#include "../../dom/reflect/DOMStringOrNull.h"

namespace Newtoo
{
    class SVGStringList
    {
    public:
        SVGStringList(SVGStringList& ref);
        SVGStringList();

        unsigned long length();

        unsigned long numberOfItems();

        void clear();

        DOMStringOrNull initialize(DOMString newItem);

        DOMStringOrNull getItem(unsigned long index);

        DOMStringOrNull insertItemBefore(DOMString newItem, unsigned long index);

        DOMStringOrNull replaceItem(DOMString newItem, unsigned long index);

        DOMStringOrNull removeItem(unsigned long index);

        DOMStringOrNull appendItem(DOMString newItem);

        void set(unsigned long index, DOMString newItem);



    protected:

    };


} // namespace Newtoo
