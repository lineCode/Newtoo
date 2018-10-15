#include "AttributeSelector.h"
#include "../SelectorObservationList.h"

namespace Newtoo
{

    AttributeSelector::AttributeSelector(DOMString aAttrName)
        :Selector(ATTRIBUTE), mAttrName(aAttrName)
    {}

    DOMString& AttributeSelector::attrName()
    {
        return mAttrName;
    }

    bool AttributeSelector::matches(SelectorObservationList& list)
    {
        for(unsigned i = 0; i < list.collection().size(); i++)
        {
            if(list.collection()[i]->hasAttribute(attrName()))
                return true;
        }
        return false;
    }
    unsigned long AttributeSelector::priority()
    {
        return ClassPriority;
    }

}
