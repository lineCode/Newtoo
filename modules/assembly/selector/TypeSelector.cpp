#include "TypeSelector.h"
#include "SelectorObservationList.h"

namespace Newtoo
{

    TypeSelector::TypeSelector(DOMString aQuery)
        :Selector(TYPE), mQuery(aQuery)
    {}

    bool TypeSelector::matches(SelectorObservationList& list)
    {
        for(unsigned i = 0; i < list.collection().size(); i++)
        {
            if(list.collection()[i]->localName() == mQuery)
                return true;
        }
        return false;
    }
    unsigned long TypeSelector::priority()
    {
        return TypePriority;
    }

}
