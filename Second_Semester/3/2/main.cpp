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
    Matrix *matrix = new Matrix(size);
    matrix->readMatrix();

    outputer->output(matrix, size);

    delete matrix;
    delete outputer;
    return 0;
}

