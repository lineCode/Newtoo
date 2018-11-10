#include "SVGURIReference.h"

namespace Newtoo
{
    SVGURIReference::SVGURIReference(SVGURIReference& ref) : mHref(ref.mHref)
    {}

    SVGURIReference::SVGURIReference()
    {

    }

    SVGAnimatedString& SVGURIReference::href()
    {
        return mHref;
    }


} // namespace Newtoo
