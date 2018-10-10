#pragma once

#include "../../dom/node/Element.h"
#include "../../dom/DOMString.h"

namespace Newtoo
{

    class SelectorObservationList;

    class Selector
    {
    public:

        enum TokenType
        {
            ID,
            TYPE,
            CLASS,

            CHILD,
            DESCEDANT,
            NEXT_SIBLING,
            SUBSEQUENT_SIBLING,

            ATTRIBUTE_EQUALS,
            ATTRIBUTE_ENDS_WITH,
            ATTRIBUTE_STARTS_WITH,
            ATTRIBUTE_STARTS_WITH_PREFIX,
            ATTRIBUTE_CONTAINS,
            ATTRIBUTE_CONTAINS_ITEM,

            PSEUDO_CLASS_ROOT,
            PSEUDO_CLASS_HOVER,
            PSEUDO_CLASS_ACTIVE,
            PSEUDO_CLASS_FOCUS,
            PSEUDO_CLASS_PRESS,
            PSEUDO_CLASS_EMPTY,
            PSEUDO_CLASS_ANY_LINK,
            PSEUDO_CLASS_VISITED,
            PSEUDO_CLASS_LINK,
            PSEUDO_CLASS_ENABLED,
            PSEUDO_CLASS_DISABLED,
            PSEUDO_CLASS_CHECKED,
            PSEUDO_CLASS_FIRST_CHILD,
            PSEUDO_CLASS_LAST_CHILD,
            PSEUDO_CLASS_ONLY_CHILD,
            PSEUDO_CLASS_FIRST_OF_TYPE,
            PSEUDO_CLASS_LAST_OF_TYPE,

            FUNCTION_NTH_CHILD,
            FUNCTION_NTH_LAST_CHILD,
            FUNCTION_NTH_OF_TYPE,
            FUNCTION_NTH_LAST_OF_TYPE,

            FUNCTION_NOT,

            UNIVERSAL
        };

        Selector(TokenType aType);

        TokenType type() const;

        virtual bool matches(SelectorObservationList& list);

        const int IdPriority = 1;
        const int ClassPriority = 10;
        const int TypePriority = 100;

        virtual unsigned long priority();

    private:

        TokenType mType;
    };

}
