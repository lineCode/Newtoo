#include "Comparator.h"
#include "../SelectorObservationList.h"

namespace Newtoo
{

    Comparator::Comparator()
        :Selector(UNIVERSAL)
    {}

    unsigned long Comparator::priority()
    {
        return ClassPriority;
    }

}
