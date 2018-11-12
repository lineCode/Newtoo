#pragma once

#include "../../dom/node/Element.h"
#include "../../cssom/style/StyleSheetListReflect.h"

namespace Newtoo
{

    class StyleAssembler
    {
    public:

        static void cascade(Element* element, StyleSheetListReflect& styles);
        static void cascade(Document* document);
    };

}
