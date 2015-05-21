#pragma once
#include "list.h"
#include "../../../Some_Useful_Things/Exceptions/elementexists.h"

class UniqueList : public List
{
public:
    UniqueList();
    ~UniqueList();

    void add(int value);
};
