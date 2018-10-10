#include "UniversalSelector.h"
#include "SelectorObservationList.h"

namespace Newtoo
{

    UniversalSelector::UniversalSelector()
        :Selector(UNIVERSAL)
    {}

    bool UniversalSelector::matches(SelectorObservationList& list)
    {
        for(unsigned i = 0; i < list.collection().size(); i++)
        {}
        return true;
    }
    unsigned long UniversalSelector::priority()
    {
        return 0;
    }

}
