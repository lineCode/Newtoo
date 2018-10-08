#pragma once

#include "../../dom/node/Element.h"

namespace Newtoo
{

    class SelectorObservationList
    {
    public:

        SelectorObservationList(Element* target);

        std::vector<Element*>& collection();

        void child();
        void descedant();
        void nextSibling();
        void subsequentSibling();

    private:

        std::vector<Element*> mCollection;
        std::vector<Element*> mTransferBuffer;
    };

}
