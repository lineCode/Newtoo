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

    protected:

        std::vector<Element*>& transferBuffer();
        void swap();

    private:

        std::vector<Element*> mCollection;
        std::vector<Element*> mTransferBuffer;
    };

}
