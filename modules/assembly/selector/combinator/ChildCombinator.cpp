#include "ChildCombinator.h"
#include "../SelectorObservationList.h"

namespace Newtoo
{

    ChildCombinator::ChildCombinator()
        :Selector(CHILD)
    {}

    bool ChildCombinator::matches(SelectorObservationList& list)
    {
        list.child();
        return true;
    }
    unsigned long ChildCombinator::priority()
    {
        return 0;
    }

}
