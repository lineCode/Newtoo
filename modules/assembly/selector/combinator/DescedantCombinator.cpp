#include "DescedantCombinator.h"
#include "../SelectorObservationList.h"

namespace Newtoo
{

    DescedantCombinator::DescedantCombinator()
        :Selector(DESCEDANT)
    {}

    bool DescedantCombinator::matches(SelectorObservationList& list)
    {
        list.descedant();
        return true;
    }
    unsigned long DescedantCombinator::priority()
    {
        return 0;
    }

}
