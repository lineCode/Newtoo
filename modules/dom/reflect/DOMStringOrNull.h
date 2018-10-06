#pragma once

#include "../DOMString.h"

namespace Newtoo
{

    class DOMStringOrNull
    {
    public:

        DOMStringOrNull(DOMString str);
        DOMStringOrNull();

        DOMString& string();
        bool hasString() const;

    private:

        DOMString mString;
        bool mHasString;
    };

}
