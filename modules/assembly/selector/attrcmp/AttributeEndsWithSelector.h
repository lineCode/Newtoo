#pragma once

#include "Comparator.h"

namespace Newtoo
{

    class AttributeEndsWithSelector : public Comparator
    {
    public:

        AttributeEndsWithSelector(DOMString aAttrName, DOMString aAttrValue);

        bool matches(SelectorObservationList& list) override;
    };

}
