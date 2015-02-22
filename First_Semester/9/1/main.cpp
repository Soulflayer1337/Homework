#include "hash.h"
#include <fstream>

bool readFromFile(const char *fileName, hashTable *hash)
{
    std::ifstream in(fileName);

    if (!in.is_open())
    {
        std::cout << "The file doesn't exist!\n";
        return false;
    }

    while (!in.eof())
    {
        MyString word;
        word.setParams(upToNewline);
        in >> word;
        addElement(hash, word);
    }

    in.close();
    return true;
}

int recordEqualStrings(MyString inputFileName, MyString outputFileName, hashTable *table)
{
    std::ifstream in(inputFileName.toChar());

    if (!in.is_open())
    {
        std::cout << "Input file doesn't exist!\n";
        return 2;
    }

    std::ofstream out(outputFileName.toChar());

    if (!out.is_open())
    {
        std::cout << "Output file doesn't exist!\n";
        in.close();
        return 3;
    }

    while (!in.eof())
    {
        MyString string;
        string.setParams(upToNewline);
        in >> string;

        if (exists(table, string))
            out << string << std::endl;
    }

    in.close();
    out.close();
    return 0;
}

int main()
{
    hashTable *hash = createHash(65536);
    MyString inputFileName;
    std::cout << "Enter first input file's name: ";
    std::cin >> inputFileName;

    if (!readFromFile(inputFileName.toChar(), hash))
    {
        deleteHash(hash);
        return 1;
    }

    std::cout << "Enter second input file's name: ";
    std::cin >> inputFileName;

    MyString outputFileName;
    std::cout << "Enter output file's name: ";
    std::cin >> outputFileName;

    int returnValue = recordEqualStrings(inputFileName, outputFileName, hash);
    deleteHash(hash);
    return returnValue;
}
