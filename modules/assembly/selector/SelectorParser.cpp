#include "SelectorParser.h"
#include "SelectorSyntax.h"

namespace Newtoo
{

    using namespace SelectorSyntax;

    SelectorStringList groupListFromString(SelectorString string)
    {
        SelectorStringList groups;

        /*
            Сначала, проверим, сколько групп,
            если всего одна, значит вернем
            сразу всю строку.
        */
        char* split = (char*)string.findChar(split_list);

        if(split == 0)
        {
            groups.push_back(string);
            return groups;
        }

        /*
            Убедившись, что групп много,
            нарезаем их по одной группе на
            строку.
        */
        groups.push_back(string);
        DOMString* target = &groups.back();
        split = (char*)target->findChar(split_list);
        do
        {
            unsigned long index = split - target->raw();
            DOMString secondPiece = target->substring(index + 1, target->size() - index - 1);
            *target = target->substring(0, index);
            groups.push_back(secondPiece);
            target = &groups.back();
            split = (char*)target->findChar(split_list);
        }
        while(split != 0);

        return groups;
    }

    SelectorData parseSelectorFromString(SelectorString string)
    {
        SelectorData dat;
        SelectorStringList groupstrlist = groupListFromString(string);

        return dat;
    }


}
