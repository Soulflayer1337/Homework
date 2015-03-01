#include <iostream>
#include "quicksorter.h"
#include "mergesorter.h"

int main()
{
    Sorter *sorter = new MergeSorter;
    Sorter *sorter2 = new QuickSorter;

    std::cout << "Enter size of the array: ";
    int n = 0;
    std::cin >> n;

    std::cout << "Enter " << n << " elements of the array:\n";

    int *array = new int[n];
    int *array2 = new int[n];

    for (int i = 0; i < n; i++)
    {
        std::cin >> array[i];
        array2[i] = array[i];
    }

    sorter->sort(array, n);
    sorter2->sort(array2, n);

    std::cout << "MergeSorter:";
    for (int i = 0; i < n; i++)
        std::cout << " " << array[i];

    std::cout << "\nQuickSorter:";
    for (int i = 0; i < n; i++)
        std::cout << " " << array2[i];
    std::cout << std::endl;

    delete[] array;
    delete[] array2;
    delete sorter;
    delete sorter2;
    return 0;
}

