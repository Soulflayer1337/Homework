#include "sortedlist.h"
#include <iostream>

SortedList::SortedList() : first(new Node(nullptr, 0))
{
}

SortedList::~SortedList()
{
    Node *currentNode = first;

    while (currentNode != nullptr)
    {
        Node *toDelete = currentNode;
        currentNode = currentNode->next;
        delete toDelete;
    }
}

void SortedList::add(int value)
{
    Node *currentNode = first;

    while (currentNode->next != nullptr && currentNode->next->value < value)
        currentNode = currentNode->next;

    currentNode->next = new Node(currentNode->next, value);
}

bool SortedList::remove(int value)
{
    Node *currentNode = first;

    while (currentNode->next != nullptr && currentNode->next->value != value)
        currentNode = currentNode->next;

    if (currentNode->next != nullptr)
    {
        Node *toRemove = currentNode->next;
        currentNode->next = toRemove->next;
        delete toRemove;
        return true;
    }

    return false;
}

void SortedList::removeAll(int value)
{
    Node *currentNode = first;

    while (currentNode->next != nullptr && currentNode->next->value != value)
        currentNode = currentNode->next;

    while (currentNode->next != nullptr && currentNode->next->value == value)
    {
        Node *toRemove = currentNode->next;
        currentNode->next = toRemove->next;
        delete toRemove;
    }
}

bool SortedList::exists(int value)
{
    Node *currentNode = first->next;

    while (currentNode != nullptr && currentNode->value != value)
        currentNode = currentNode->next;

    return currentNode != nullptr;
}

bool SortedList::isEmpty()
{
    return first->next == nullptr;
}

void SortedList::print()
{
    Node *currentNode = first->next;

    while(currentNode != nullptr)
    {
        std::cout << currentNode->value << " ";
        currentNode = currentNode->next;
    }
    std::cout << std::endl;
}

SortedList::Node::Node(SortedList::Node *nxt, int val) : next(nxt), value(val)
{
}
