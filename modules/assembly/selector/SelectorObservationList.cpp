#include "SelectorObservationList.h"

namespace Newtoo
{

    SelectorObservationList::SelectorObservationList(Element* target)
    {
        collection().push_back(target);
    }
    std::vector<Element*>& SelectorObservationList::collection()
    {
        return mCollection;
    }

}
