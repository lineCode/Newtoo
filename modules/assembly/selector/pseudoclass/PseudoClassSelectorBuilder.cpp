#include "PseudoClassSelectorBuilder.h"
#include "../SelectorSyntax.h"

namespace Newtoo
{

    void PseudoClassSelectorBuilder::appendSelector(SelectorGroup group, DOMString selector)
    {
        if(!selector.hasChar(SelectorSyntax::function_arg_begin, 0))
        {
            // Определяем и добавляем функцию
        } else
        {
            // Определяем и добавляем псевдо класс
        }
    }

}
