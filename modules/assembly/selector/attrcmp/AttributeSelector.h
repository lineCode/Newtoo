#pragma once

#include "../Selector.h"

namespace Newtoo
{

    class AttributeSelector : public Selector
    {
    public:

        AttributeSelector(DOMString aAttrName);

        DOMString& attrName();

        bool matches(SelectorObservationList& list) override;
        unsigned long priority() override;

    private:

        DOMString mAttrName;
    };

}
