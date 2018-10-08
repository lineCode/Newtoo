#pragma once

#include "SelectorGroup.h"

namespace Newtoo
{

    class SelectorPseudoClassBuilder
    {
    public:

        static void appendSelector(SelectorGroup group, DOMString selector);
    };

}
