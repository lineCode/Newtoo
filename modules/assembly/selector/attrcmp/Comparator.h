#pragma once

#include "../Selector.h"

namespace Newtoo
{

    class Comparator : public Selector
    {
    public:

        Comparator();

        unsigned long priority() override;
    };

}
