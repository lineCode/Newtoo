#include "AttributeContainsItemSelector.h"
#include "../SelectorObservationList.h"

namespace Newtoo
{

    AttributeContainsItemSelector::AttributeContainsItemSelector(DOMString aAttrName, DOMString aAttrValue)
        :Comparator(ATTRIBUTE_CONTAINS_ITEM, aAttrName, aAttrValue)
    {}

    const char token_list_split[] = " ";

    bool AttributeContainsItemSelector::matches(SelectorObservationList& list)
    {
        for(unsigned i = 0; i < list.collection().size(); i++)
        {
            DOMString middleValue = token_list_split;
            middleValue += attrValue() + token_list_split;

            if(list.collection()[i]->getAttribute(attrName()).startsWith(attrValue()))
                return true;
            else if(list.collection()[i]->getAttribute(attrName()).contains(middleValue))
                return true;
            else if(list.collection()[i]->getAttribute(attrName()).endsWith(attrValue()))
                return true;
        }
        return false;
    }

}
