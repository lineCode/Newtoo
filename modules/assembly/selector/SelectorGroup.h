#pragma once

#include "Selector.h"

#include <vector>

namespace Newtoo
{

    class SelectorGroup
    {
    public:

        typedef std::vector<Selector> SelectorList;

        SelectorGroup();

        SelectorList& list();

        enum Result
        {
            FirstLetter,
            FistLine,
            Before,
            After,

            Assigned,
            NotMatches
        };

        Result matches(Element* element);
        /*
            Если element соответствуетвсем селекторам в группе,
            он возратит mMatchesResult, иначе Result::NotMatches
        */

        void setMatchesResult(Result result);
        /*
            C помощью setMatchesResult можно изменить результат,
            который будет возращатся, если элемент соответствует
            всем селекторам.
        */

    private:

        Result mMatchesResult;
        SelectorList mList;
    };

}
