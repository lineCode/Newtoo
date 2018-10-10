#pragma once

#include "../Selector.h"

namespace Newtoo
{

    class Comparator : public Selector
    {
    public:

        Comparator(DOMString aAttrName, DOMString aAttrValue);

        unsigned long priority() override;

        DOMString attrName();
        DOMString attrValue();

    private:

        DOMString mAttrName;
        DOMString mAttrValue;
    };

}
