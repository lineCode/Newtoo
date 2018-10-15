#include "AttributeStartsWithPrefixSelector.h"
#include "../SelectorObservationList.h"

namespace Newtoo
{

    AttributeStartsWithPrefixSelector::AttributeStartsWithPrefixSelector(DOMString aAttrName,
                                                                        DOMString aAttrValue)
        :Comparator(ATTRIBUTE_STARTS_WITH_PREFIX, aAttrName, aAttrValue)
    {}

    const char value_prefix_end[] = "-";

    bool AttributeStartsWithPrefixSelector::matches(SelectorObservationList& list)
    {
        for(unsigned i = 0; i < list.collection().size(); i++)
        {
            if(list.collection()[i]->getAttribute(attrName()) == attrValue()
            or list.collection()[i]->getAttribute(attrName()).startsWith(attrValue() + value_prefix_end))
                return true;
        }
        return false;
    }

}
