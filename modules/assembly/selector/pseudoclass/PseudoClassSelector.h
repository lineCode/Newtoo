#pragma once

#include "../Selector.h"

namespace Newtoo
{

    class PseudoClassSelector : public Selector
    {
    public:

        PseudoClassSelector(DOMString aName);

        unsigned long priority() override;

        DOMString name();

    private:

        DOMString mName;
    };

}
