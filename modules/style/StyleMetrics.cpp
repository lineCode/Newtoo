#include "StyleMetrics.h"

namespace Newtoo
{

    StyleMetrics::StyleMetrics(CSSStyleDeclaration aFrom)
    {
        aFrom.cssText();
    }

}
