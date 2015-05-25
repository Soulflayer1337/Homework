#pragma once
#include "list.h"
#include "../../../Some_Useful_Things/Exceptions/elementexists.h"

/// @brief The UniqueList class - the list without repeat.
class UniqueList : public List
{
public:
    UniqueList();
    ~UniqueList();

    /// @brief add - adds new element or throws exception if that element exists
    void add(int value);
};
