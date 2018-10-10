#include "IdSelector.h"
#include "SelectorObservationList.h"

namespace Newtoo
{

    IdSelector::IdSelector(DOMString aQuery)
        :Selector(ID), mQuery(aQuery)
    {}

    bool IdSelector::matches(SelectorObservationList& list)
    {
        for(unsigned i = 0; i < list.collection().size(); i++)
        {
            if(list.collection()[i]->id() == mQuery)
                return true;
        }
        return false;
    }
    unsigned long IdSelector::priority()
    {
        return IdPriority;
    }

}
