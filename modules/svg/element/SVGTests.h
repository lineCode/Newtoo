#pragma once

#include "SVGStringList.h"

namespace Newtoo
{
    class SVGTests
    {
    public:
        SVGTests(SVGTests& ref);
        SVGTests();

        SVGStringList& requiredExtensions();
        SVGStringList& systemLanguage();



    protected:
        SVGStringList mRequiredExtensions;
        SVGStringList mSystemLanguage;

    };


} // namespace Newtoo
