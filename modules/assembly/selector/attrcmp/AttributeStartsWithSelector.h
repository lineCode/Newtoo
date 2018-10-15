#pragma once

#include "Comparator.h"

namespace Newtoo
{

    class AttributeStartsWithSelector : public Comparator
    {
    public:

        AttributeStartsWithSelector(DOMString aAttrName, DOMString aAttrValue);

        bool matches(SelectorObservationList& list) override;
    };

}
