#pragma once

#include "../dom/node/Element.h"

namespace Newtoo
{

    class CSSSelectorParser
    {
    public:

        enum Matches
        {
            Assigned,
            Before,
            After,
            NotMatches
        };

        static Matches elementMatches(Element* element, DOMString list);
        static bool elementMatchesItem(Element* element, DOMString text);
        static unsigned long computePriority(DOMString text);
        static DOMString computePriorityString(DOMString text);
    };

}
