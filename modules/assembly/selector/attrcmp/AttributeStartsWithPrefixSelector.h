#pragma once

#include "Comparator.h"

namespace Newtoo
{

    class AttributeStartsWithPrefixSelector : public Comparator
    {
    public:

        AttributeStartsWithPrefixSelector(DOMString aAttrName, DOMString aAttrValue);

        bool matches(SelectorObservationList& list) override;
    };

}
