#include "sortedlist.h"
#include <iostream>

SortedList::SortedList() : numberOfElements(0), head(new Node(nullptr, 0))
{
}

SortedList::~SortedList()
{
    while (head != nullptr)
    {
        Node *toDelete = head;
        head = head->next;
        delete toDelete;
    }
}

int SortedList::compareTo(const IComparable *obj) const
{
    const SortedList *sortedList = dynamic_cast<const SortedList*> (obj);

    if (sortedList)
        return (sortedList->count() > count() ? -1 : sortedList->count() < count());
    else
        return 42;
}

bool SortedList::isEqual(const IComparable *obj) const
{
    const SortedList *sortedList = dynamic_cast<const SortedList*> (obj);

    if (sortedList != nullptr && !compareTo(sortedList))
    {
        int *firstArray = convertToArray();

        if (firstArray == nullptr)
            return true;

        int *secondArray = sortedList->convertToArray();

        bool unequal = false;

        for (int i = 0; i < numberOfElements && !unequal; i++)
            if (firstArray[i] != secondArray[i])
                unequal = true;

        delete[] firstArray;
        delete[] secondArray;
        return !unequal;
    }
    else
        return false;
}

void SortedList::add(const int value)
{
    Node *currentNode = head;

    while (currentNode->next != nullptr && currentNode->next->value < value)
        currentNode = currentNode->next;

    currentNode->next = new Node(currentNode->next, value);
    numberOfElements++;
}

void SortedList::remove(const int value)
{
    Node *currentNode = head;

    while (currentNode->next != nullptr && currentNode->next->value != value)
        currentNode = currentNode->next;

    if (currentNode->next != nullptr)
    {
        Node *toRemove = currentNode->next;
        currentNode->next = toRemove->next;
        delete toRemove;
        numberOfElements--;
    }
}

void SortedList::removeAll(const int value)
{
    Node *currentNode = head;

    while (currentNode->next != nullptr && currentNode->next->value != value)
        currentNode = currentNode->next;

    while (currentNode->next != nullptr && currentNode->next->value == value)
    {
        Node *toRemove = currentNode->next;
        currentNode->next = toRemove->next;
        delete toRemove;
        numberOfElements--;
    }
}

IComparable *SortedList::copy() const
{
    SortedList *sortedList = new SortedList();

    int *array = convertToArray();

    for (int i = numberOfElements - 1; i >= 0; i--)
        sortedList->add(array[i]);

    delete[] array;
    return sortedList;
}

bool SortedList::exists(int value) const
{
    Node *currentNode = head->next;

    while (currentNode != nullptr && currentNode->value != value)
        currentNode = currentNode->next;

    return currentNode != nullptr;
}

int SortedList::count(int value) const
{
    Node *currentNode = head->next;
    int count = 0;

    while (currentNode != nullptr && currentNode->value <= value)
    {
        count += currentNode->value == value;
        currentNode = currentNode->next;
    }

    return count;
}

int SortedList::count() const
{
    return numberOfElements;
}

int *SortedList::convertToArray() const
{
    if (!numberOfElements)
        return nullptr;

    int *array = new int[numberOfElements];

    Node *currentNode = head->next;

    int ptr = 0;
    while (currentNode != nullptr)
    {
        array[ptr++] = currentNode->value;
        currentNode = currentNode->next;
    }

    return array;
}

void SortedList::print() const
{
    Node *currentElement = head->next;

    while (currentElement != nullptr)
    {
        std::cout << currentElement->value << " ";
        currentElement = currentElement->next;
    }

    std::cout << std::endl;
}

SortedList::Node::Node(Node *nxt, int val) : next(nxt), value(val)
{
}
