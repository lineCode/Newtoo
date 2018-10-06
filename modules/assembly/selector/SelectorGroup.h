#pragma once

#include "Selector.h"

#include <vector>

namespace Newtoo
{

    const char FirstletterPseudoElementName[] = "firstletter";
    const char FirstlinePseudoElementName[] = "fistline";
    const char SelectionPseudoElementName[] = "Selection";
    const char BeforePseudoElementName[] = "before";
    const char AfterPseudoElementName[] = "after";

    class SelectorGroup
    {
    public:

        typedef std::vector<Selector> SelectorList;

        SelectorGroup();

        SelectorList& list();

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

    private:

        Result mMatchesResult;
        SelectorList mList;
    };

}
