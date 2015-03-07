#pragma once

/**
 * @brief The Sorter class - Abstract type for sorting.
 */
class Sorter
{
public:
    /**
     * @brief sort - Virtual function which sorts the array
     * @param array - An array of numbers to sort
     * @param size - The size of the array
     */
    virtual void sort(int *array, int size) = 0;
protected:
    /**
     * @brief swap - swaps two elements.
     */
    void swap(int &first, int &second);
};
