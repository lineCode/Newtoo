#include "SVGTests.h"

namespace Newtoo
{
    SVGTests::SVGTests(SVGTests& ref): mRequiredExtensions(ref.mRequiredExtensions),
        mSystemLanguage(ref.mSystemLanguage)
    {}

    SVGTests::SVGTests()
    {

    }

    SVGStringList& SVGTests::requiredExtensions()
    {
        return mRequiredExtensions;
    }

    SVGStringList& SVGTests::systemLanguage()
    {
        return mSystemLanguage;
    }


} // namespace Newtoo
