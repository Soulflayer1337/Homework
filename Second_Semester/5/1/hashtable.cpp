#include "hashtable.h"
#include <iostream>

HashTable::HashTable(IHashFunction *function, unsigned int rebuildNum) : guard(new Node(new Node(nullptr, function), nullptr)), current(nullptr),
                                                                            pointer(nullptr), iterator(0), rebuildNumber(rebuildNum)
{
    current = guard->next;
    pointer = guard;
}

HashTable::~HashTable()
{
    while (guard)
    {
        Node *toDelete = guard;
        guard = guard->next;
        delete toDelete;
    }
}

void HashTable::add(const std::string &obj)
{
    current->numberOfElements++;
    current->table[current->function->getHash(obj)].add(obj);
    rebuild();
}

void HashTable::remove(const std::string &obj)
{
    Node *ptr = findElement(obj);

    if (!ptr)
    {
        rebuild();
        throw MissingElementException();
    }

    ptr->numberOfElements--;
    ptr->table[ptr->function->getHash(obj)].remove(obj);

    rebuild();
}

bool HashTable::exists(const std::string &obj)
{
    rebuild();
    return (findElement(obj));
}

void HashTable::printStatistics() const
{
    Node *ptr = guard->next;
    unsigned int numberOfCells = 0;
    unsigned int numberOfEmptyCells = 0;
    unsigned int numberOfElements = 0;
    unsigned int hihgerLength = 0;

    while (ptr)
    {
        int length = ptr->function->getModule();

        for (int i = 0; i < length; i++)
            if (ptr->table[i].isEmpty())
                numberOfEmptyCells++;
            else
                hihgerLength = std::max(hihgerLength, ptr->table[i].getLength());

        numberOfElements += ptr->numberOfElements;
        numberOfCells += length;
        ptr = ptr->next;
    }

    std::cout << "Number of cells: " << numberOfCells << "\n"
              << "Number of empty cells: " << numberOfEmptyCells << "\n"
              << "Number of elements: " << numberOfElements << "\n"
              << "Load Factor: " << double(numberOfElements) / numberOfCells << "\n"
              << "Hihger length of the chain: " << hihgerLength << "\n"
              << "Middle length of the chain: " << double(numberOfElements) / (numberOfCells - numberOfEmptyCells) << "\n";
}

void HashTable::changeFunction(IHashFunction *function)
{
    Node *ptr = guard;

    while (ptr->next && ptr->next->function != function)
        ptr = ptr->next;

    if (!ptr->next)
        ptr->next = new Node(nullptr, function);

    current = ptr->next;
    rebuild();
}

void HashTable::rebuild()
{
    unsigned int changedNumber = 0;

    while (guard->next->next && changedNumber < rebuildNumber)
    {
        unsigned int &numberOfElements = pointer->next->numberOfElements;

        while (changedNumber < rebuildNumber && numberOfElements)
        {
            while (!pointer->next->table[iterator].isEmpty() && changedNumber < rebuildNumber)
            {
                add(pointer->next->table[iterator].pop());
                changedNumber++;
                numberOfElements--;
            }

            changedNumber++;
            iterator++;
        }

        if (!numberOfElements)
        {
            changedNumber++;
            Node *toDelete = pointer->next;
            pointer->next = toDelete->next;

            if (!pointer->next)
                pointer = guard;

            iterator = 0;
        }
    }
}

HashTable::Node *HashTable::findElement(const std::string &obj)
{
    Node *ptr = guard->next;

    while (ptr && !ptr->table[ptr->function->getHash(obj)].exists(obj))
        ptr = ptr->next;

    return ptr;
}

HashTable::Node::Node(HashTable::Node *nxt, IHashFunction *func) : next(nxt), table(nullptr), function(func), numberOfElements(0)
{
    if (func)
        table = new List[function->getModule()];
}

HashTable::Node::~Node()
{
    if (function)
    {
        delete function;
        delete table;
    }
}
