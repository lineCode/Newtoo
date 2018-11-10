#pragma once

typedef char SVGAnimatedRect;
typedef char SVGAnimatedPreserveAspectRatio;

namespace Newtoo
{
    class SVGFitToViewBox
    {
    public:
        SVGFitToViewBox(SVGFitToViewBox& ref);
        SVGFitToViewBox();

        SVGAnimatedRect& viewBox();

        SVGAnimatedPreserveAspectRatio& preserveAspectRatio();



    protected:
        SVGAnimatedRect mViewBox;
        SVGAnimatedPreserveAspectRatio mPreserveAspectRatio;

    };


} // namespace Newtoo
