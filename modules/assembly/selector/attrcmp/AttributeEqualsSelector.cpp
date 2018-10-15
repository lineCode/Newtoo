#include "AttributeEqualsSelector.h"
#include "../SelectorObservationList.h"

namespace Newtoo
{

    AttributeEqualsSelector::AttributeEqualsSelector(DOMString aAttrName, DOMString aAttrValue)
        :Comparator(ATTRIBUTE_EQUALS, aAttrName, aAttrValue)
    {}

    bool AttributeEqualsSelector::matches(SelectorObservationList& list)
    {
        for(unsigned i = 0; i < list.collection().size(); i++)
        {
            if(list.collection()[i]->getAttribute(attrName()) == attrValue())
                return true;
        }
        return false;
    }

}
