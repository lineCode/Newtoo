#pragma once

#include "../CSSOMString.h"

#include <vector>

namespace Newtoo
{

    class CSSRule;

    class CSSComputedStyleDeclaration
    {
    public:

        /*
            Пока это просто набросок, не более
        */

        CSSComputedStyleDeclaration();

        unsigned long length() const;
        DOMString item(unsigned long index);
        DOMString getPropertyValue(DOMString property);

        CSSRule* parentRule() const                         { return mParentRule; }
        DOMString cssFloat();

        DOMString get(DOMString aProperty);

        CSSComputedStyleDeclaration(CSSComputedStyleDeclaration& reference, CSSRule* newParent)
            :mParentRule(newParent)
        {
            reference.length();
            /* StyleMetrics не будет копироваться */
        }

    private:

        CSSRule* mParentRule;
    };

}
