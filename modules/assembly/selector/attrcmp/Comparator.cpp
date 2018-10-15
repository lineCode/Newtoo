#include "Comparator.h"
#include "../SelectorObservationList.h"

namespace Newtoo
{

    Comparator::Comparator(TokenType aType, DOMString aAttrName, DOMString aAttrValue)
        :Selector(aType), mAttrName(aAttrName), mAttrValue(aAttrValue)
    {}

    DOMString& Comparator::attrName()
    {
        return mAttrName;
    }
    DOMString& Comparator::attrValue()
    {
        return mAttrValue;
    }

    unsigned long Comparator::priority()
    {
        return ClassPriority;
    }

}
