#pragma once

/*

     Смотрите подробную документацию к интерфейсу DOMRectReadOnly на MDN
     https://developer.mozilla.org/ru/docs/Web/API/DOMRectReadOnly

*/

namespace Newtoo
{

    class DOMRectReadOnly
    {
    public:

        DOMRectReadOnly(double aX, double aY, double aWidth, double aHeight);

        static DOMRectReadOnly fromRect(double aX = 0, double aY = 0, double aWidth = 0,
                                        double aHeight = 0)
        {
            return DOMRectReadOnly(aX, aY, aWidth, aHeight);
        }

        double x() const            { return mX; }
        double y() const            { return mY; }
        double width() const        { return mWidth; }
        double height() const       { return mHeight; }

        double left()               { return x(); }
        double top()                { return y(); }
        double right()              { return x() + width(); }
        double bottom()             { return y() + height(); }

    protected:

        double mX;
        double mY;
        double mWidth;
        double mHeight;
    };

}
