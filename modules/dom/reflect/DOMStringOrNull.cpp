#include "DOMStringOrNull.h"

namespace Newtoo
{

    DOMStringOrNull::DOMStringOrNull(DOMString str)
        :mString(str), mHasString(true)
    {}

    DOMStringOrNull::DOMStringOrNull()
        :mHasString(false)
    {}

    DOMString& DOMStringOrNull::string()
    {
        return mString;
    }

    bool DOMStringOrNull::hasString() const
    {
        return mHasString;
    }

}
