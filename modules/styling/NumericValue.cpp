#include "NumericValue.h"
#include "misc/StringHash.h"
#include "metrics/StyleMetrics.h"

namespace Newtoo
{
    Unit unitFromString(CSSOMString str)
    {
        switch(sh(str))
        {
            case csh("ch"):
            {
                return Unit::Ch;
                break;
            }
            case csh("cm"):
            {
                return Unit::Cm;
                break;
            }
            case csh("deg"):
            {
                return Unit::Deg;
                break;
            }
            case csh("em"):
            {
                return Unit::Em;
                break;
            }
            case csh("ex"):
            {
                return Unit::Ex;
                break;
            }
            case csh("fr"):
            {
                return Unit::Fr;
                break;
            }
            case csh("grad"):
            {
                return Unit::Grad;
                break;
            }
            case csh("in"):
            {
                return Unit::In;
                break;
            }
            case csh("mm"):
            {
                return Unit::Mm;
                break;
            }
            case csh("pc"):
            {
                return Unit::Pc;
                break;
            }
            case csh("%"):
            {
                return Unit::Percentages;
                break;
            }
            case csh("pt"):
            {
                return Unit::Pt;
                break;
            }
            case csh("px"):
            {
                return Unit::Px;
                break;
            }
            case csh("q"):
            {
                return Unit::Q;
                break;
            }
            case csh("rad"):
            {
                return Unit::Rad;
                break;
            }
            case csh("rem"):
            {
                return Unit::Rem;
                break;
            }
            case csh("turn"):
            {
                return Unit::Turn;
                break;
            }
            case csh("vh"):
            {
                return Unit::Vh;
                break;
            }
            case csh("vmax"):
            {
                return Unit::Vmax;
                break;
            }
            case csh("vmin"):
            {
                return Unit::Vmin;
                break;
            }
            case csh("vw"):
            {
                return Unit::Vw;
                break;
            }
        }
        return Unit::Px;
    }

    CSSOMString unitToString(Unit unit)
    {
        switch(unit)
        {
            case Unit::Ch:
            {
                return CSSOMString("ch");
                break;
            }
            case Unit::Cm:
            {
                return CSSOMString("cm");
                break;
            }
            case Unit::Deg:
            {
                return CSSOMString("deg");
                break;
            }
            case Unit::Em:
            {
                return CSSOMString("em");
                break;
            }
            case Unit::Ex:
            {
                return CSSOMString("ex");
                break;
            }
            case Unit::Fr:
            {
                return CSSOMString("fr");
                break;
            }
            case Unit::Grad:
            {
                return CSSOMString("grad");
                break;
            }
            case Unit::In:
            {
                return CSSOMString("in");
                break;
            }
            case Unit::Mm:
            {
                return CSSOMString("mm");
                break;
            }
            case Unit::Pc:
            {
                return CSSOMString("pc");
                break;
            }
            case Unit::Percentages:
            {
                return CSSOMString("%");
                break;
            }
            case Unit::Pt:
            {
                return CSSOMString("pt");
                break;
            }
            case Unit::Px:
            {
                return CSSOMString("px");
                break;
            }
            case Unit::Q:
            {
                return CSSOMString("q");
                break;
            }
            case Unit::Rad:
            {
                return CSSOMString("rad");
                break;
            }
            case Unit::Rem:
            {
                return CSSOMString("rem");
                break;
            }
            case Unit::Turn:
            {
                return CSSOMString("turn");
                break;
            }
            case Unit::Vh:
            {
                return CSSOMString("vh");
                break;
            }
            case Unit::Vmax:
            {
                return CSSOMString("vmax");
                break;
            }
            case Unit::Vmin:
            {
                return CSSOMString("vmin");
                break;
            }
            case Unit::Vw:
            {
                return CSSOMString("vw");
                break;
            }
        }
        return CSSOMString("incorrect_unit");
    }

    NumericValue::NumericValue(NumericValue& ref) : mValue(ref.mValue), mUnit(ref.mUnit)
    {}

    NumericValue::NumericValue(double aValue, Unit aUnit) : mValue(aValue), mUnit(aUnit)
    {}

    NumericValue::NumericValue() : mValue(0.0), mUnit(Unit::Px)
    {}

    double NumericValue::value() const
    {
        return mValue;
    }

    void NumericValue::setValue(double aValue)
    {
        mValue = aValue;
    }

    Unit NumericValue::unit() const
    {
        return mUnit;
    }

    void NumericValue::setUnit(Unit aUnit)
    {
        mUnit = aUnit;
    }

    double NumericValue::toPx(double relativeValue, StyleMetrics* relativeMetrics)
    {
        switch(unit())
        {
            case Unit::Ch:
            {
                return value() * relativeMetrics->valueOfPropertyWithNumericValue("font-size") / 2;
                break;
            }
            case Unit::Cm:
            {
                return value() * 38;
                return 0.0;
                break;
            }
            case Unit::Deg:
            {
                return value() * 38;
                return 0.0;
                break;
            }
            case Unit::Em:
            {
                return 0.0;
                break;
            }
            case Unit::Ex:
            {
                return 0.0;
                break;
            }
            case Unit::Fr:
            {
                return 0.0;
                break;
            }
            case Unit::Grad:
            {
                return 0.0;
                break;
            }
            case Unit::In:
            {
                return 0.0;
                break;
            }
            case Unit::Mm:
            {
                return 0.0;
                break;
            }
            case Unit::Pc:
            {
                return 0.0;
                break;
            }
            case Unit::Percentages:
            {
                return 0.0;
                break;
            }
            case Unit::Pt:
            {

                return 0.0;
                break;
            }
            case Unit::Px:
            {

                return 0.0;
                break;
            }
            case Unit::Q:
            {

                return 0.0;
                break;
            }
            case Unit::Rad:
            {

                return 0.0;
                break;
            }
            case Unit::Rem:
            {

                return 0.0;
                break;
            }
            case Unit::Turn:
            {

                return 0.0;
                break;
            }
            case Unit::Vh:
            {

                return 0.0;
                break;
            }
            case Unit::Vmax:
            {

                return 0.0;
                break;
            }
            case Unit::Vmin:
            {

                return 0.0;
                break;
            }
            case Unit::Vw:
            {

                return 0.0;
                break;
            }
        }
        return value();
    }

    CSSOMString NumericValue::toString()
    {
        CSSOMString number;
        number.fromDouble(value());

        return number + unitToString(unit());
    }

    NumericValue NumericValue::fromString(CSSOMString str)
    {
        String valuestr;
        String unitstr;

        for(size_t i = 0; i < str.size(); i++)
        {
            if(isdigit(str[i]))
            {
                valuestr += i;
            } else
            {
                unitstr += i;
            }
        }

        NumericValue ret;
        ret.mValue = valuestr.toDouble();
        ret.mUnit = unitFromString(unitstr);

        return ret;
    }


} // namespace Newtoo
