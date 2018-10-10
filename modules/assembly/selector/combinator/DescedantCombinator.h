#pragma once

#include "../Selector.h"

namespace Newtoo
{

    class DescedantCombinator : public Selector
    {
    public:

        DescedantCombinator();

        bool matches(SelectorObservationList& list) override;
        unsigned long priority() override;
    };

}
