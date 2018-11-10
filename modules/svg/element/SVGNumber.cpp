#include "SVGNumber.h"

namespace Newtoo
{

    SVGNumber::SVGNumber(SVGNumber& ref) : mValue(ref.mValue)
    {}

    SVGNumber::SVGNumber() : mValue(0)
    {

    }

    float SVGNumber::value() const
    {
        return mValue;
    }

    void SVGNumber::setValue(float aValue)
    {
        mValue = aValue;
    }

}
