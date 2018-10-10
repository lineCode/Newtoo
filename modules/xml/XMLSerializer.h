#pragma once

#include "../dom/node/Node.h"

namespace Newtoo
{

    class XMLSerializer
    {
    public:

        DOMString serializeToString(Node* root);
    };

}
