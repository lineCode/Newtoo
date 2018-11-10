#pragma once

#include "SVGNumber.h"

namespace Newtoo
{
    class SVGNumberList
    {
    public:
        SVGNumberList(SVGNumberList& ref);
        SVGNumberList();

        unsigned long length();

        unsigned long numberOfItems();

        void clear();

        SVGNumber* initialize(SVGNumber newItem);

        SVGNumber* getItem(unsigned long index);

        SVGNumber* insertItemBefore(SVGNumber newItem, unsigned long index);

        SVGNumber* replaceItem(SVGNumber newItem, unsigned long index);

        SVGNumber* removeItem(unsigned long index);

        SVGNumber* appendItem(SVGNumber newItem);

        void set(unsigned long index, SVGNumber newItem);



    protected:

    };


} // namespace Newtoo
