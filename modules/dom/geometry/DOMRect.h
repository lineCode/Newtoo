#pragma once

#include "DOMRectReadOnly.h"

/*
    DOMRect - тоже, что и DOMRectReadOnly за исключением того, что
    свойства доступны для записи.
*/

namespace Newtoo
{

    class DOMRect : public DOMRectReadOnly
    {
    public:

        DOMRect(double aX, double aY, double aWidth, double aHeight);

        static DOMRect fromRect(double aX = 0, double aY = 0, double aWidth = 0, double aHeight = 0)
        {
            return DOMRect(aX, aY, aWidth, aHeight);
        }
        static DOMRect fromRect(DOMRectReadOnly& aRect)
        {
            return DOMRect(aRect.x(), aRect.y(), aRect.width(), aRect.height());
        }

        void setX(double aX);
        void setY(double aY);
        void setWidth(double aWidth);
        void setHeight(double aHeight);
    };

}
