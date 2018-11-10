#pragma once

typedef char SVGAnimatedString;

namespace Newtoo
{
    class SVGURIReference
    {
    public:
        SVGURIReference(SVGURIReference& ref);
        SVGURIReference();

        SVGAnimatedString& href();



    protected:
        SVGAnimatedString mHref;

    };


} // namespace Newtoo
