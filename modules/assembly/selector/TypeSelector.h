#pragma once

#include "Selector.h"

namespace Newtoo
{

    class TypeSelector : public Selector
    {
    public:

        TypeSelector(DOMString aQuery);

        bool matches(SelectorObservationList& list) override;
        unsigned long priority() override;

        DOMString query();

    private:

        DOMString mQuery;
    };

}
