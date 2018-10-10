#pragma once

#include "Selector.h"

namespace Newtoo
{

    class IdSelector : public Selector
    {
    public:

        IdSelector(DOMString aQuery);

        bool matches(SelectorObservationList& list) override;
        unsigned long priority() override;

        DOMString query();

    private:

        DOMString mQuery;
    };

}
