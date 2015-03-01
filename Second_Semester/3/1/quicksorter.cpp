#include "quicksorter.h"

void QuickSorter::sort(int *array, int size)
{
    if (size < 2)
        return;

    if (size == 2)
    {
        if (array[0] > array[1])
            swap(array[0], array[1]);
        return;
    }

    int leftIt = 0;
    int rightIt = size - 1;
    int middle = (array[(leftIt + rightIt) / 2]);

    while (leftIt < rightIt)
    {
        while (leftIt < rightIt && array[leftIt] < middle)
            leftIt++;

        while (rightIt > leftIt && array[rightIt] > middle)
            rightIt--;

        if (leftIt != rightIt) {
            swap(array[leftIt], array[rightIt]);
            leftIt++;
            rightIt--;
        }
    }

    sort(array, rightIt + 1);
    sort(&array[leftIt], size - leftIt);
}
