#include "PseudoClassSelector.h"
#include "../SelectorObservationList.h"

namespace Newtoo
{

    PseudoClassSelector::PseudoClassSelector(DOMString aName)
        :Selector(UNIVERSAL), mName(aName)
    {}

    unsigned long PseudoClassSelector::priority()
    {
        return ClassPriority;
    }

    DOMString PseudoClassSelector::name()
    {
        return mName;
    }

}
