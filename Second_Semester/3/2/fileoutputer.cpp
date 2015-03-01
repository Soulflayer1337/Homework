#include <fstream>
#include <iostream>
#include "fileoutputer.h"

void FileOutputer::output(int **matrix, int size)
{
    std::ofstream out("output.txt");

    if (!out.is_open())
    {
        std::cout << "An unexpected error occured!\n";
        return;
    }

    int *array = makeOutputArray(matrix, size);
    int length = size * size;

    for (int i = 0; i < length; i++)
        out << array[i] << " ";

    out << std::endl;
    out.close();
    std::cout << "Check the file \"output.txt\"\n";
    delete[] array;
}
