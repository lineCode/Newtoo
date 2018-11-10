#include "SVGGeometryElement.h"

namespace Newtoo
{
    SVGGeometryElement::SVGGeometryElement(SVGGeometryElement& ref) : SVGGraphicsElement(ref), mPathLength(ref.mPathLength)
    {}

    SVGGeometryElement::SVGGeometryElement()
    {

    }

    SVGAnimatedNumber& SVGGeometryElement::pathLength()
    {
        return mPathLength;
    }

    bool SVGGeometryElement::isPointInFill(double x, double y, double z, double w)
    {

    }

    bool SVGGeometryElement::isPointInStroke(double x, double y, double z, double w)
    {

    }

    float SVGGeometryElement::getTotalLength()
    {

    }

    DOMPoint SVGGeometryElement::getPointAtLength(float distance)
    {

    }


} // namespace Newtoo
