#include "SVGLength.h"

namespace Newtoo
{
    SVGLength::SVGLength(SVGLength& ref) : mUnitType(ref.mUnitType), mValue(ref.mValue)
    {}

    SVGLength::SVGLength()
    {

    }

    unsigned short SVGLength::unitType() const
    {
        return mUnitType;
    }

    float SVGLength::value() const
    {
        return mValue;
    }

    void SVGLength::setValue(float aValue)
    {
        mValue = aValue;
    }

    float SVGLength::valueInSpecifiedUnits()
    {

    }

    void SVGLength::setValueInSpecifiedUnits(float aValueInSpecifiedUnits)
    {

    }

    DOMString SVGLength::valueAsString()
    {

    }

    void SVGLength::setValueAsString(DOMString aValueAsString)
    {

    }

    void SVGLength::newValueSpecifiedUnits(unsigned short unitType, float valueInSpecifiedUnits)
    {

    }

    void SVGLength::convertToSpecifiedUnits(unsigned short unitType)
    {

    }


} // namespace Newtoo
