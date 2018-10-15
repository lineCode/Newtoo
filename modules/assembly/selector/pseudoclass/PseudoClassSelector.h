#pragma once

#include "../Selector.h"

namespace Newtoo
{

    class PseudoClassSelector : public Selector
    {
    public:

        PseudoClassSelector(TokenType aType, DOMString aName);

        unsigned long priority() override;

        DOMString name();

    private:

        DOMString mName;
    };

}
