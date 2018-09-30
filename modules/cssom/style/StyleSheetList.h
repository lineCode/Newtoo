#pragma once

#include "StyleSheet.h"

#include <vector>

namespace Newtoo
{

    class StyleSheetList
    {
    public:

        StyleSheetList();

        virtual StyleSheet* item(unsigned long index);
        virtual unsigned long length();

    private:

        void appendStyleSheet(StyleSheet* aStyleSheet);

        std::vector<StyleSheet*> mList;
    };

}
