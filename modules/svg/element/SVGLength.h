#pragma once

#include "../../dom/DOMString.h"

namespace Newtoo
{
    class SVGLength
    {
    public:
        SVGLength(SVGLength& ref);
        SVGLength();

        const unsigned short SVG_LENGTHTYPE_UNKNOWN = 0;
        const unsigned short SVG_LENGTHTYPE_NUMBER = 1;
        const unsigned short SVG_LENGTHTYPE_PERCENTAGE = 2;
        const unsigned short SVG_LENGTHTYPE_EMS = 3;
        const unsigned short SVG_LENGTHTYPE_EXS = 4;
        const unsigned short SVG_LENGTHTYPE_PX = 5;
        const unsigned short SVG_LENGTHTYPE_CM = 6;
        const unsigned short SVG_LENGTHTYPE_MM = 7;
        const unsigned short SVG_LENGTHTYPE_IN = 8;
        const unsigned short SVG_LENGTHTYPE_PT = 9;
        const unsigned short SVG_LENGTHTYPE_PC = 10;

        unsigned short unitType() const;

        float value() const;
        void setValue(float aValue);

        float valueInSpecifiedUnits();
        void setValueInSpecifiedUnits(float aValueInSpecifiedUnits);

        DOMString valueAsString();
        void setValueAsString(DOMString aValueAsString);

        void newValueSpecifiedUnits(unsigned short unitType, float valueInSpecifiedUnits);

        void convertToSpecifiedUnits(unsigned short unitType);



    protected:
        unsigned short mUnitType;
        float mValue;

    };


} // namespace Newtoo
