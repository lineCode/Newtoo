#pragma once

#include "../../../dom/DOMString.h"
#include "../../../dom/node/container/NodeList.h"

namespace Newtoo
{

    class Element;

    class HTMLCollection
    {
    public:

        HTMLCollection() {}

        enum Mode
        {
            NORMAL,
            BY_CLASS_NAME,
            BY_TAG_NAME,
            BY_TAG_NAME_NS,
            BY_NAME,
            IMAGES,
            EMBEDS,
            LINKS,
            FORMS,
            SCRIPTS,
            FORM_CONTROLS,
            TABLE_CELLS,
            TABLE_ROWS
        };

        HTMLCollection(NodeList* aNodeList, Mode aMode = NORMAL, DOMString aArg = "",
                       DOMString aArg2 = "");

        void setTargetNodeList(NodeList* aNodeList);

        unsigned long length();
        Element* item(unsigned long index);
        Element* namedItem(DOMString name);

        bool acceptToCollection(Element* childElement);

    protected:

        DOMString mArg;
        DOMString mArg2;
        Mode mMode;

        NodeList* mNodeListRef;
    };

}
