#include "PseudoClassSelector.h"
#include "../SelectorObservationList.h"

namespace Newtoo
{

    PseudoClassSelector::PseudoClassSelector(TokenType aType, DOMString aName)
        :Selector(aType), mName(aName)
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
