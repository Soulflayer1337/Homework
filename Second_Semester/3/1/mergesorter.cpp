#include "mergesorter.h"

void MergeSorter::sort(int *array, int size)
{
    if (size < 2)
        return;

    int leftSize = size / 2;
    int rightSize = size - leftSize;

    int *leftArray = new int[leftSize];
    int *rightArray = new int[rightSize];

    for (int i = 0; i < leftSize; i++)
        leftArray[i] = array[i];

    for (int j = 0; j < rightSize; j++)
        rightArray[j] = array[leftSize + j];

    sort(leftArray, leftSize);
    sort(rightArray, rightSize);

    int leftIt = 0;
    int rightIt = 0;

    while (leftIt < leftSize || rightIt < rightSize)
        if (leftIt == leftSize || (rightIt != rightSize && leftArray[leftIt] > rightArray[rightIt]))
        {
            array[leftIt + rightIt] = rightArray[rightIt];
            rightIt++;
        }
        else
        {
            array[leftIt + rightIt] = leftArray[leftIt];
            leftIt++;
        }

    delete[] leftArray;
    delete[] rightArray;
}
