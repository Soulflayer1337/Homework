#include "uniquelist.h"

UniqueList::UniqueList() : List()
{
}

UniqueList::~UniqueList()
{
}

void UniqueList::add(int value)
{
    if (exists(value))
        throw ElementExistsException();
    List::add(value);
}

