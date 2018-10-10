#pragma once

#include "../Selector.h"

namespace Newtoo
{

    class ChildCombinator : public Selector
    {
    public:

        ChildCombinator();

        bool matches(SelectorObservationList& list) override;
        unsigned long priority() override;
    };

}
