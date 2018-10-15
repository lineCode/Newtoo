#include "AttributeStartsWithSelector.h"
#include "../SelectorObservationList.h"

namespace Newtoo
{

    AttributeStartsWithSelector::AttributeStartsWithSelector(DOMString aAttrName, DOMString aAttrValue)
        :Comparator(ATTRIBUTE_STARTS_WITH, aAttrName, aAttrValue)
    {}

    bool AttributeStartsWithSelector::matches(SelectorObservationList& list)
    {
        for(unsigned i = 0; i < list.collection().size(); i++)
        {
            if(list.collection()[i]->getAttribute(attrName()).startsWith(attrValue()))
                return true;
        }
        return false;
    }

}
