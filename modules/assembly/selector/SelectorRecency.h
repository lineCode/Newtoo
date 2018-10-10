#pragma once

namespace Newtoo
{

    class SelectorRecency
    {
    public:

        SelectorRecency();

        bool updated();
        void renew();

        void affect();

    private:

        bool mNeedAffect;
    };

}
