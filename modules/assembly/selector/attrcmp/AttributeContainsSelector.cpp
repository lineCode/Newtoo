#include "AttributeContainsSelector.h"
#include "../SelectorObservationList.h"

namespace Newtoo
{

    AttributeContainsSelector::AttributeContainsSelector(DOMString aAttrName, DOMString aAttrValue)
        :Comparator(ATTRIBUTE_CONTAINS, aAttrName, aAttrValue)
    {}

    bool AttributeContainsSelector::matches(SelectorObservationList& list)
    {
        for(unsigned i = 0; i < list.collection().size(); i++)
        {
            if(list.collection()[i]->getAttribute(attrName()).contains(attrValue()))
                return true;
        }
        return false;
    }

}
