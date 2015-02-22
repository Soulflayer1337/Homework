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
        word.setParams(onlyLetters);
        in >> word;
        addElement(hash, word);
    }

    in.close();
    return true;
}

int main()
{
    hashTable *hash = createHash(49081);
    MyString fileName;
    std::cout << "Enter the file's name: ";
    std::cin >> fileName;

    if (!readFromFile(fileName.toChar(), hash))
        return 1;

    printStatus(hash);
    deleteHash(hash);
    return 0;
}
