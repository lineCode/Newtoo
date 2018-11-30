#pragma once

#include "StylingEngine_dependencies.h"

namespace Newtoo
{
    class StyleMetrics;

    enum class Unit
    {
        In = 0x0,
        Cm = 0x1,
        Mm = 0x2,
        Q = 0x3,
        Pt = 0x4,
        Pc = 0x5,
        Px = 0x6,
        Deg = 0x7,
        Grad = 0x8,
        Rad = 0x9,
        Turn = 0xa,
        Percentages = 0xb,
        Rem = 0xc,
        Em = 0xd,
        Ex = 0xe,
        Ch = 0xf,
        Vw = 0x10,
        Vh = 0x11,
        Vmin = 0x12,
        Vmax = 0x13,
        Fr = 0x14
    };

    Unit unitFromString(CSSOMString str);
    CSSOMString unitToString(Unit unit);

    class NumericValue
    {
    public:
        NumericValue(double aValue, Unit aUnit);
        NumericValue(NumericValue& ref);
        NumericValue();

        double value() const;
        void setValue(double aValue);

        Unit unit() const;
        void setUnit(Unit aUnit);

        double toPx(double relativeValue = 0.0, StyleMetrics* relativeMetrics = 0);

        CSSOMString toString();

        static NumericValue fromString(CSSOMString str);



    protected:
        double mValue;
        Unit mUnit;

    };


} // namespace Newtoo
