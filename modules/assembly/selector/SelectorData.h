#include "SelectorGroup.h"

#include <vector>

namespace Newtoo
{

    class SelectorData
    {
    public:

        typedef std::vector<SelectorGroup> GroupList;

        unsigned long priority() const;
        GroupList& groups();

        void calcPriority();

    private:

        unsigned long mPriority;
        GroupList mData;
    };

}
