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

}
