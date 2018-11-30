#include "StringHash.h"

namespace Newtoo
{

    unsigned int cstrHashRt(const char* str, int h)
    {
        return !str[h] ? 5381 : (cstrHash(str, h+1) * 33) ^ str[h];
    }

    unsigned int strHash(String str)
    {
        return cstrHashRt(str.raw());
    }

}
