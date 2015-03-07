#pragma once
#include "sorter.h"

/**
 * @brief The QuickSorter class - Uses quick sort algorithm
 */
class QuickSorter : public Sorter
{
public:
    void sort(int *array, int size);
};
