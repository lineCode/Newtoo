#include "NextSiblingCombinator.h"
#include "../SelectorObservationList.h"

namespace Newtoo
{

    NextSiblingCombinator::NextSiblingCombinator()
        :Selector(NEXT_SIBLING)
    {}

    bool NextSiblingCombinator::matches(SelectorObservationList& list)
    {
        list.nextSibling();
        return true;
    }
    unsigned long NextSiblingCombinator::priority()
    {
        return 0;
    }

}
