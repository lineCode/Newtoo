#pragma once

#include "../dom/DOMString.h"

namespace Newtoo
{

    const char EscapeChar[] = " ";

    class CSSUnitValue;

    class CSS
    {
    public:

        static DOMString escape(DOMString ident);

        // Из стандарта CSS Typed OM

        static CSSUnitValue number(double value);
        static CSSUnitValue percent(double value);

        static CSSUnitValue em(double value);
        static CSSUnitValue ex(double value);
        static CSSUnitValue ch(double value);
        static CSSUnitValue ic(double value);
        static CSSUnitValue rem(double value);
        static CSSUnitValue lh(double value);
        static CSSUnitValue rlh(double value);
        static CSSUnitValue vw(double value);
        static CSSUnitValue vh(double value);
        static CSSUnitValue vi(double value);
        static CSSUnitValue vb(double value);
        static CSSUnitValue vmin(double value);
        static CSSUnitValue vmax(double value);
        static CSSUnitValue cm(double value);
        static CSSUnitValue mm(double value);
        static CSSUnitValue Q(double value);
        static CSSUnitValue in(double value);
        static CSSUnitValue pt(double value);
        static CSSUnitValue pc(double value);
        static CSSUnitValue px(double value);

        static CSSUnitValue deg(double value);
        static CSSUnitValue grad(double value);
        static CSSUnitValue rad(double value);
        static CSSUnitValue turn(double value);

        static CSSUnitValue s(double value);
        static CSSUnitValue ms(double value);

        static CSSUnitValue Hz(double value);
        static CSSUnitValue kHz(double value);

        static CSSUnitValue dpi(double value);
        static CSSUnitValue dpcm(double value);
        static CSSUnitValue dppx(double value);

        static CSSUnitValue fr(double value);
    };

}
