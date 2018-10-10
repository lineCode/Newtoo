#pragma once

#include "Selector.h"

namespace Newtoo
{

    class ClassSelector : public Selector
    {
    public:

        ClassSelector(DOMString aQuery);

        bool matches(SelectorObservationList& list) override;
        unsigned long priority() override;

        DOMString query();

    private:

        DOMString mQuery;
    };

}
