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

    void SelectorObservationList::child()
    {
        swap();
        for(unsigned i = 0; i < transferBuffer().size(); i++)
        {
            Element* parent = transferBuffer()[i]->parentElement();
            if(parent == 0)
                continue;

            collection().push_back(parent);
        }
    }

    void SelectorObservationList::descedant()
    {
        swap();
        for(unsigned i = 0; i < transferBuffer().size(); i++)
        {
            Element* parent = transferBuffer()[i]->parentElement();
            while(parent != 0)
            {
                collection().push_back(parent);
                parent = parent->parentElement();
            }
        }
    }

    void SelectorObservationList::nextSibling()
    {
        swap();
        for(unsigned i = 0; i < transferBuffer().size(); i++)
        {
            Element* prev = transferBuffer()[i]->previousElementSibling();
            while(prev != 0)
            {
                collection().push_back(prev);
                prev = prev->previousElementSibling();
            }
        }
    }

    void SelectorObservationList::subsequentSibling()
    {
        swap();
        for(unsigned i = 0; i < transferBuffer().size(); i++)
        {
            Element* parent = transferBuffer()[i]->parentElement();
            if(parent == 0)
                continue;

            for(unsigned i = 0; i < parent->childNodes().length(); i++)
            {
                if(parent->childNodes().item(i)->nodeType() == Node::ELEMENT_NODE)
                {
                    Element* el = (Element*)parent->childNodes().item(i);
                    if(el != transferBuffer()[i])
                        collection().push_back(el);
                }
            }
        }
    }

    std::vector<Element*>& SelectorObservationList::transferBuffer()
    {
        return mTransferBuffer;
    }

    void SelectorObservationList::swap()
    {
        mTransferBuffer.swap(mCollection);
        mCollection.clear();
    }

}
