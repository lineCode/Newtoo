#include "SelectorGroup.h"

namespace Newtoo
{

    SelectorGroup::SelectorGroup()
        :mMatchesResult(Assigned)
    {}

    SelectorGroup::Result SelectorGroup::matches(Element* element)
    {
        for(unsigned i = 0; i < list().size(); i++)
            if(!list()[i].matches(element))
                return NotMatches;

        return mMatchesResult;
    }

    SelectorGroup::SelectorList& SelectorGroup::list()
    {
        return mList;
    }

    void SelectorGroup::setMatchesResult(Result result)
    {
        mMatchesResult = result;
    }

}
