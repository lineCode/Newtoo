#pragma once

#include "../Selector.h"

namespace Newtoo
{

    class SubsequentCombinator : public Selector
    {
    public:

        SubsequentCombinator();

        bool matches(SelectorObservationList& list) override;
        unsigned long priority() override;
    };

}
