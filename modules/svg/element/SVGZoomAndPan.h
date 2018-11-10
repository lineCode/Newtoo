#pragma once

namespace Newtoo
{
    class SVGZoomAndPan
    {
    public:
        SVGZoomAndPan(SVGZoomAndPan& ref);
        SVGZoomAndPan();

        const unsigned short SVG_ZOOMANDPAN_UNKNOWN = 0;
        const unsigned short SVG_ZOOMANDPAN_DISABLE = 1;
        const unsigned short SVG_ZOOMANDPAN_MAGNIFY = 2;

        unsigned short zoomAndPan() const;
        void setZoomAndPan(unsigned short aZoomAndPan);



    protected:
        unsigned short mZoomAndPan;

    };


} // namespace Newtoo
