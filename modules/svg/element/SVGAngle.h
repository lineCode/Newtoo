#pragma once

#include "../../dom/DOMString.h"

namespace Newtoo
{
    class SVGAngle
    {
    public:
        SVGAngle(SVGAngle& ref);
        SVGAngle();

        const unsigned short SVG_ANGLETYPE_UNKNOWN = 0;
        const unsigned short SVG_ANGLETYPE_UNSPECIFIED = 1;
        const unsigned short SVG_ANGLETYPE_DEG = 2;
        const unsigned short SVG_ANGLETYPE_RAD = 3;
        const unsigned short SVG_ANGLETYPE_GRAD = 4;

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
