#pragma once

#include "../StylingEngine_dependencies.h"

#define csh cstrHash
#define sh  strHash

namespace Newtoo
{
    constexpr unsigned int cstrHash(const char* str, int h = 0)
    {
        return !str[h] ? 5381 : (cstrHash(str, h+1) * 33) ^ str[h];
    }

    unsigned int cstrHashRt(const char* str, int h = 0); // runtime
    unsigned int strHash(String str);
}
