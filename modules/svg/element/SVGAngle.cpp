#include "SVGAngle.h"

namespace Newtoo
{
    SVGAngle::SVGAngle(SVGAngle& ref)
    {}

    SVGAngle::SVGAngle()
    {

    }

    unsigned short SVGAngle::unitType() const
    {
        return mUnitType;
    }

    float SVGAngle::value() const
    {
        return mValue;
    }

    void SVGAngle::setValue(float aValue)
    {
        mValue = aValue;
    }

    float SVGAngle::valueInSpecifiedUnits()
    {

    }

    void SVGAngle::setValueInSpecifiedUnits(float aValueInSpecifiedUnits)
    {

    }

    DOMString SVGAngle::valueAsString()
    {

    }

    void SVGAngle::setValueAsString(DOMString aValueAsString)
    {

    }

    void SVGAngle::newValueSpecifiedUnits(unsigned short unitType, float valueInSpecifiedUnits)
    {

    }

    void SVGAngle::convertToSpecifiedUnits(unsigned short unitType)
    {

    }


} // namespace Newtoo
