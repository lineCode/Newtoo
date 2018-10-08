#include "SelectorGroup.h"
#include "SelectorObservationList.h"

namespace Newtoo
{

    SelectorGroup::SelectorGroup()
        :mMatchesResult(Assigned)
    {}

    SelectorGroup::Result SelectorGroup::matches(Element* element)
    {
        SelectorObservationList obslist(element);

        for(unsigned i = 0; i < sequence().size(); i++)
            if(!sequence()[i].matches(obslist))
                return NotMatches;

        return mMatchesResult;
    }

    SelectorGroup::SelectorSequence& SelectorGroup::sequence()
    {
        return mSequence;
    }

    void SelectorGroup::setMatchesResult(Result result)
    {
        mMatchesResult = result;
    }

}
