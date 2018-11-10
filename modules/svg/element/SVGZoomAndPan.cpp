#include "SVGZoomAndPan.h"

namespace Newtoo
{
    SVGZoomAndPan::SVGZoomAndPan(SVGZoomAndPan& ref) : mZoomAndPan(ref.mZoomAndPan)
    {}

    SVGZoomAndPan::SVGZoomAndPan()
    {

    }

    unsigned short SVGZoomAndPan::zoomAndPan() const
    {
        return mZoomAndPan;
    }

    void SVGZoomAndPan::setZoomAndPan(unsigned short aZoomAndPan)
    {
        mZoomAndPan = aZoomAndPan;
    }


} // namespace Newtoo
