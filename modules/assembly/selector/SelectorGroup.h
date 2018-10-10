#pragma once

#include "Selector.h"

#include <vector>

namespace Newtoo
{

    const char FirstletterPseudoElementSuffix[] = "::firstletter";
    const char FirstlinePseudoElementSuffix[] = "::fistline";
    const char SelectionPseudoElementSuffix[] = "::Selection";
    const char BeforePseudoElementSuffix[] = "::before";
    const char AfterPseudoElementSuffix[] = "::after";

    class SelectorGroup
    {
    public:

        typedef std::vector<Selector> SelectorSequence;

        SelectorGroup();

        SelectorSequence& sequence();

        enum Result
        {
            Firstletter,
            Firstline,
            Selection,
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

        unsigned long priority();

    private:

        Result mMatchesResult;
        SelectorSequence mSequence;
    };

}
