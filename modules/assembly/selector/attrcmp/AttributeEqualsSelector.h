#pragma once

#include "Comparator.h"

namespace Newtoo
{

    class AttributeEqualsSelector : public Comparator
    {
    public:

        AttributeEqualsSelector(DOMString aAttrName, DOMString aAttrValue);

        bool matches(SelectorObservationList& list) override;
    };

}
