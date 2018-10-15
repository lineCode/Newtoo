#include "AttributeEndsWithSelector.h"
#include "../SelectorObservationList.h"

namespace Newtoo
{

    AttributeEndsWithSelector::AttributeEndsWithSelector(DOMString aAttrName, DOMString aAttrValue)
        :Comparator(ATTRIBUTE_ENDS_WITH, aAttrName, aAttrValue)
    {}

    bool AttributeEndsWithSelector::matches(SelectorObservationList& list)
    {
        for(unsigned i = 0; i < list.collection().size(); i++)
        {
            if(list.collection()[i]->getAttribute(attrName()).endsWith(attrValue()))
                return true;
        }
        return false;
    }

}
