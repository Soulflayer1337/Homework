#include <fstream>
#include "Arithmetic_tree.h"

void memoryRealloc(char *&string, int &size)
{
    char *newString = new char[size + 10];
    memcpy(newString, string, size);
    delete[] string;
    string = newString;
    size += 10;
}

char *getFileName()
{
    int size = 10;
    char *fileName = new char[size];
    int it = 0;
    char symb = '\0';

    while ((symb = std::cin.get()) != '\n')
    {
        if (it + 2 == size)
            memoryRealloc(fileName, size);
        fileName[it++] = symb;
    }

    if (it == 0)
    {
        delete[] fileName;
        fileName = nullptr;
    }
    else
    {
        fileName[it++] = '\0';

        if (it + 1 != size)
        {
            char *newString = new char[it + 1];
            memcpy(newString, fileName, it + 1);
            delete[] fileName;
            fileName = newString;
        }
    }

    return fileName;
}

int main()
{
    std::cout << "Welcome to the program, which implements arithmetic tree!\nEnter the name of the file, that contains the expression.\nEnter nothinh to type the expression here: ";
    char *fileName = getFileName();

    ArithmeticTree *tree = createArithmeticTree();

    if (fileName == nullptr)
    {
        std::cout << "Enter your expression: ";
        buildTree(tree);
    }
    else
    {
        std::ifstream in(fileName);

        if (in.is_open())
        {
            buildTree(tree, in);
            in.close();
        }
        else
        {
            std::cout << "Failed to open file! Enter expression here: ";
            buildTree(tree);
        }

    }

    printTree(tree);
    std::cout << std::endl << countAsnwer(tree);
    deleteArithmeticTree(tree);
    return 0;
}

