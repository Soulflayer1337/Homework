#include <iostream>
#include "consoleoutputer.h"

void ConsoleOutputer::output(int **matrix, int size)
{
    int *array = makeOutputArray(matrix, size);
    int length = size * size;

    for (int i = 0; i < length; i++)
        std::cout << array[i] << " ";

    std::cout << std::endl;
    delete[] array;
}
