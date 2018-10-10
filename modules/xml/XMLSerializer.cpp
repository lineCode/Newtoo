#include "XMLSerializer.h"
#include "../assembly/html/HTMLSerializer.h"

namespace Newtoo
{

    DOMString XMLSerializer::serializeToString(Node* root)
    {
        HTMLSerializerNodeSequence list;
        list.push_back(root);

        return HTMLSerializer::serializeToString(list);
    }

}
