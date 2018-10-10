#pragma once

#include "../SelectorGroup.h"

namespace Newtoo
{

    class PseudoClassSelectorBuilder
    {
    public:

        static void appendSelector(SelectorGroup group, DOMString selector);
    };

}
