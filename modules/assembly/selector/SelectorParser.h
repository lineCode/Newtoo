#include "SelectorData.h"

namespace Newtoo
{

    typedef DOMString SelectorString;
    typedef std::vector<SelectorString> SelectorStringList;

    class SelectorParser
    {
    public:

        static SelectorData parseSelectorFromString(SelectorString string);
    };

}
