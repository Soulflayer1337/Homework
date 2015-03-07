#pragma once
#include "sorter.h"

/**
 * @brief The MergeSorter class - Uses merge sort algorithm.
 */
class MergeSorter : public Sorter
{
public:
    void sort(int *array, int size);
};
