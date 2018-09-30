#pragma once

#include "StyleSheetList.h"
#include "../../html/element/collection/HTMLCollection.h"

namespace Newtoo
{

    class StyleSheetListReflect final : public StyleSheetList
    {
    public:
        StyleSheetListReflect(NodeList* reference);

        StyleSheet* item(unsigned long index) override;
        unsigned long length() override;

        HTMLCollection& collection()                        { return mCollection; }

    private:

        HTMLCollection mCollection;
    };

}
