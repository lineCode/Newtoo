#include "Selector.h"
#include "SelectorObservationList.h"

namespace Newtoo
{


    Selector::Selector(TokenType aType)
        :mType(aType)
    {}

    Selector::TokenType Selector::type() const
    {
        return mType;
    }

    bool Selector::matches(SelectorObservationList& list)
    {
        for(unsigned i = 0; i < list.collection().size(); i++)
        {
            if(!list.collection()[i]->isPseudoElement())
                return true;
        }
        return false;
    }
    unsigned long Selector::priority()
    {
        return 0;
    }

}
