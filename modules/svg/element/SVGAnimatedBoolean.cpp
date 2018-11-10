#include "SVGAnimatedBoolean.h"

namespace Newtoo
{
    SVGAnimatedBoolean::SVGAnimatedBoolean(SVGAnimatedBoolean& ref)
        : mBaseVal(ref.mBaseVal), mAnimVal(ref.mAnimVal)
    {}

    SVGAnimatedBoolean::SVGAnimatedBoolean()
    {

    }

    bool SVGAnimatedBoolean::baseVal() const
    {
        return mBaseVal;
    }

    void SVGAnimatedBoolean::setBaseVal(bool aBaseVal)
    {
        mBaseVal = aBaseVal;
    }

    bool SVGAnimatedBoolean::animVal() const
    {
        return mAnimVal;
    }


} // namespace Newtoo
