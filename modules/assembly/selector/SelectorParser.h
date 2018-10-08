#include "SelectorData.h"

namespace Newtoo
{

    typedef DOMString SelectorString;
    typedef std::vector<SelectorString> SelectorStringList;

    class SelectorParser
    {
    public:

        static SelectorStringList groupListFromString(SelectorString string);
        static SelectorGroup parseGroupFromString(SelectorString string);
        static SelectorData parseSelectorFromString(SelectorString string);
    };

}
