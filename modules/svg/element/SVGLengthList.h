#pragma once

#include "SVGLength.h"

namespace Newtoo
{
    class SVGLengthList
    {
    public:
        SVGLengthList(SVGLengthList& ref);
        SVGLengthList();

        unsigned long length();

        unsigned long numberOfItems();

        void clear();

        SVGLength* initialize(SVGLength newItem);

        SVGLength* getItem(unsigned long index);

        SVGLength* insertItemBefore(SVGLength newItem, unsigned long index);

        SVGLength* replaceItem(SVGLength newItem, unsigned long index);

        SVGLength* removeItem(unsigned long index);

        SVGLength* appendItem(SVGLength newItem);

        void set(unsigned long index, SVGLength newItem);



    protected:

    };


} // namespace Newtoo
