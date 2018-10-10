#pragma once

#include "../Selector.h"

namespace Newtoo
{

    class Comparator : public Selector
    {
    public:

        Comparator(DOMString mAttrName, DOMString mAttrValue);

        unsigned long priority() override;

        DOMString attrName();
        DOMString attrValue();

    private:

        DOMString mAttrName;
        DOMString mAttrValue;
    };

}
