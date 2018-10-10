#include "Comparator.h"
#include "../SelectorObservationList.h"

namespace Newtoo
{

    Comparator::Comparator(DOMString aAttrName, DOMString aAttrValue)
        :Selector(UNIVERSAL), mAttrName(aAttrName), mAttrValue(aAttrValue)
    {}

    unsigned long Comparator::priority()
    {
        return ClassPriority;
    }

}
