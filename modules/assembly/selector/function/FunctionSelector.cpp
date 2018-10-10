#include "FunctionSelector.h"
#include "../SelectorObservationList.h"

namespace Newtoo
{

    FunctionSelector::FunctionSelector(DOMString aName, DOMString aArgs)
        :Selector(UNIVERSAL), mName(aName), mArgs(aArgs)
    {}

    unsigned long FunctionSelector::priority()
    {
        return ClassPriority;
    }

    DOMString FunctionSelector::name()
    {
        return mName;
    }

    DOMString FunctionSelector::args()
    {
        return mArgs;
    }

}
