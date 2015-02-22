#include "hash.h"

struct hashTable
{
    List **array;
    size_t sizeOfArray;
    size_t numberOfElements;
};



hashTable *createHash(size_t size)
{
    hashTable *table = new hashTable;
    table->sizeOfArray = size;
    table->array = new List*[size];

    for (size_t i = 0; i < size; i++)
        table->array[i] = createList();

    table->numberOfElements = 0;
    return table;
}



void deleteHash(hashTable *table)
{
    for (size_t i = 0; i < table->sizeOfArray; i++)
        deleteList(table->array[i]);

    delete table->array;
    delete table;
}



size_t hashFunction(MyString value, unsigned long long module)
{
    const int multipler = 53;
    unsigned long long hash = 0;
    unsigned long long m_pow = 1;

    for (size_t i = 0; i < value.length(); i++)
    {
        hash = (hash + int(value[i] - 'a' + 1) * m_pow) % module;
        m_pow = (m_pow * multipler) % module;
    }

    return hash;
}



void addElement(hashTable *table, MyString value)
{
    size_t hash = hashFunction(value, table->sizeOfArray);
    table->numberOfElements += addElement(value, table->array[hash]);
}



void printStatus(hashTable *table)
{
    std::cout << "Load factor: " << double(table->numberOfElements) / table->sizeOfArray << std::endl;

    size_t countOfEmpty = 0;
    List *list = table->array[0];

    for (size_t i = 0; i < table->sizeOfArray; i++)
    {
        countOfEmpty += isEmpty(table->array[i]);
        if (lengthOfList(list) < lengthOfList(table->array[i]))
            list = table->array[i];
    }

    size_t countOfNonEmpty = table->sizeOfArray - countOfEmpty;
    std::cout << "Average length: " << (countOfNonEmpty == 0? 0 : double(table->numberOfElements) / countOfNonEmpty) << std::endl;
    printStatus(list);
    std::cout << "The number of the different word's in hash-table: " << table->numberOfElements << std::endl
              << "The number of empty cells in the table: " << countOfEmpty << std::endl;
}


bool exists(hashTable *table, MyString value)
{
    size_t hash = hashFunction(value, table->sizeOfArray);
    return exists(table->array[hash], value);
}
