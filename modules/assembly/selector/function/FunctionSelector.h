#pragma once

#include "../Selector.h"

namespace Newtoo
{

    class FunctionSelector : public Selector
    {
    public:

        FunctionSelector(DOMString aName, DOMString aArgs);

        unsigned long priority() override;

        DOMString name();
        DOMString args();

    private:

        DOMString mName;
        DOMString mArgs;
    };

}
