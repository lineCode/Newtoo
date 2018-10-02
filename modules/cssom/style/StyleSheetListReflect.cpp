#include "StyleSheetListReflect.h"
#include "../../html/element/HTMLStyleElement.h"

namespace Newtoo
{

    StyleSheetListReflect::StyleSheetListReflect(NodeList* reference)
        :mCollection(reference, HTMLCollection::BY_TAG_NAME, "style")
    {}

    StyleSheet* StyleSheetListReflect::item(unsigned long index)
    {
        return itemReflect(index);
    }

    unsigned long StyleSheetListReflect::length()
    {
        return lengthReflect();
    }

    StyleSheet* StyleSheetListReflect::itemReflect(unsigned long index)
    {
        HTMLStyleElement* elm = (HTMLStyleElement*)mCollection.item(index);

        if(elm == 0)
            return 0;

        return elm->sheet();
    }

    unsigned long StyleSheetListReflect::lengthReflect()
    {
        return mCollection.length();
    }

}
