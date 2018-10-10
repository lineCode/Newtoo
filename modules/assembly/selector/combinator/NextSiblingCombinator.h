#pragma once

#include "../Selector.h"

namespace Newtoo
{

    class NextSiblingCombinator : public Selector
    {
    public:

        NextSiblingCombinator();

        bool matches(SelectorObservationList& list) override;
        unsigned long priority() override;
    };

}
