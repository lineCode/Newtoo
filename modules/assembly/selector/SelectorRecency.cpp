#include "SelectorRecency.h"

namespace Newtoo
{

    SelectorRecency::SelectorRecency()
        :mNeedAffect(true)
    {}

    bool SelectorRecency::updated()
    {
        return mNeedAffect == true;
    }
    void SelectorRecency::renew()
    {
        mNeedAffect = true;
    }

    void SelectorRecency::affect()
    {
        mNeedAffect = false;
    }
}
