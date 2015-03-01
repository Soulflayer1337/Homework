#include <iostream>
#include "consoleoutputer.h"
#include "fileoutputer.h"

int main()
{
    std::cout << "Enter:\n'1' - to use the console output\n'2' - to use the file output\nAnything else to exit\n";
    int mod = 0;
    std::cin >> mod;

    Outputer *outputer = nullptr;

    switch (mod)
    {
    case 1:
    {
        outputer = new ConsoleOutputer;
        break;
    }
    case 2:
    {
        outputer = new FileOutputer;
        break;
    }
    default:
    {
        std::cout << "Goodbye!\n";
        return 0;
    }
    }

    std::cout << "Enter width of the matrix: ";
    int size = 0;
    std::cin >> size;
    std::cout << "Enter the matrix: ";
    int **matrix = new int*[size];

    for (int i = 0; i < size; i++)
    {
        matrix[i] = new int[size];

        for (int j = 0; j < size; j++)
            std::cin >> matrix[i][j];
    }

    outputer->output(matrix, size);

    for (int i = 0; i < size; i++)
        delete[] matrix[i];

    delete[] matrix;
    delete outputer;
    return 0;
}

