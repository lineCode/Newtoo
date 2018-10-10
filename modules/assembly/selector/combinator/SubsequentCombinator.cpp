#include "SubsequentCombinator.h"
#include "../SelectorObservationList.h"

namespace Newtoo
{

    SubsequentCombinator::SubsequentCombinator()
        :Selector(UNIVERSAL)
    {}

    bool SubsequentCombinator::matches(SelectorObservationList& list)
    {
        list.subsequentSibling();
        return true;
    }
    unsigned long SubsequentCombinator::priority()
    {
        return 0;
    }

}
