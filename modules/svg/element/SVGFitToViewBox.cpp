#include "SVGFitToViewBox.h"

namespace Newtoo
{
    SVGFitToViewBox::SVGFitToViewBox(SVGFitToViewBox& ref) : mViewBox(ref.mViewBox), mPreserveAspectRatio(ref.mPreserveAspectRatio)
    {}

    SVGFitToViewBox::SVGFitToViewBox()
    {

    }

    SVGAnimatedRect& SVGFitToViewBox::viewBox()
    {
        return mViewBox;
    }

    SVGAnimatedPreserveAspectRatio& SVGFitToViewBox::preserveAspectRatio()
    {
        return mPreserveAspectRatio;
    }


} // namespace Newtoo
