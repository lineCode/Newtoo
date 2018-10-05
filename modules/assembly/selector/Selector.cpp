#include "Selector.h"

namespace Newtoo
{


    Selector::Selector(TokenType aType)
        :mType(aType)
    {}

    Selector::TokenType Selector::type() const
    {
        return mType;
    }

    bool Selector::matches(Element *element)
    {
        return !element->isPseudoElement();
    }
    unsigned long Selector::priority()
    {
        return 0;
    }

}
