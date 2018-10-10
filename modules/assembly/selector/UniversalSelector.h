#pragma once

#include "Selector.h"

namespace Newtoo
{

    class UniversalSelector : public Selector
    {
    public:

        UniversalSelector();

        bool matches(SelectorObservationList& list) override;
        unsigned long priority() override;
    };

}
