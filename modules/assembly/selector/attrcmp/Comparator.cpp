#include "Comparator.h"
#include "../SelectorObservationList.h"

namespace Newtoo
{

    Comparator::Comparator(DOMString mAttrName, DOMString mAttrValue)
        :Selector(UNIVERSAL)
    {}

    unsigned long Comparator::priority()
    {
        return ClassPriority;
    }

}
