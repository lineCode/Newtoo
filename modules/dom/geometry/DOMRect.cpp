#include "DOMRect.h"

namespace Newtoo
{

    DOMRect::DOMRect(double aX, double aY, double aWidth, double aHeight)
        :DOMRectReadOnly(aX, aY, aWidth, aHeight)
    {}

    void DOMRect::setX(double aX)
    {
        mX = aX;
    }
    void DOMRect::setY(double aY)
    {
        mY = aY;
    }
    void DOMRect::setWidth(double aWidth)
    {
        mWidth = aWidth;
    }
    void DOMRect::setHeight(double aHeight)
    {
        mHeight = aHeight;
    }

}
