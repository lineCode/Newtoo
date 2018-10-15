#pragma once

#include "Comparator.h"

namespace Newtoo
{

    class AttributeContainsSelector : public Comparator
    {
    public:

        AttributeContainsSelector(DOMString aAttrName, DOMString aAttrValue);

        bool matches(SelectorObservationList& list) override;
    };

}
