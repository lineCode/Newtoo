#include "SelectorData.h"

namespace Newtoo
{

    unsigned long SelectorData::priority() const
    {
        return mPriority;
    }
    SelectorData::GroupList& SelectorData::groups()
    {
        return mData;
    }

    void SelectorData::calcPriority()
    {
        unsigned long p;
        for(unsigned i = 0; i < groups().size(); i++)
            p+= groups()[i].priority();

        mPriority = p;
    }

}
