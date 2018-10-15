#pragma once

#include "Comparator.h"

namespace Newtoo
{

    class AttributeContainsItemSelector : public Comparator
    {
    public:

        AttributeContainsItemSelector(DOMString aAttrName, DOMString aAttrValue);

        bool matches(SelectorObservationList& list) override;
    };

}
