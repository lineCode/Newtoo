#pragma once

#include "SVGGraphicsElement.h"

typedef char SVGAnimatedNumber;
typedef char DOMPoint;

namespace Newtoo
{
    class SVGGeometryElement : public SVGGraphicsElement
    {
    public:
        SVGGeometryElement(SVGGeometryElement& ref);
        SVGGeometryElement();

        SVGAnimatedNumber& pathLength();

        bool isPointInFill(double x = 0, double y = 0, double z = 0, double w = 1);

        bool isPointInStroke(double x = 0, double y = 0, double z = 0, double w = 1);

        float getTotalLength();

        DOMPoint getPointAtLength(float distance);



    protected:
        SVGAnimatedNumber mPathLength;

    };


} // namespace Newtoo
