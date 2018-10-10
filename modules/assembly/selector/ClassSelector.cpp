#include "ClassSelector.h"
#include "SelectorObservationList.h"

namespace Newtoo
{

    ClassSelector::ClassSelector(DOMString aQuery)
        :Selector(CLASS), mQuery(aQuery)
    {}

    bool ClassSelector::matches(SelectorObservationList& list)
    {
        for(unsigned i = 0; i < list.collection().size(); i++)
        {
            if(list.collection()[i]->classList().contains(mQuery))
                return true;
        }
        return false;
    }
    unsigned long ClassSelector::priority()
    {
        return ClassPriority;
    }

}
