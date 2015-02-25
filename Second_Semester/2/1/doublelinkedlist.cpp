#include "doublelinkedlist.h"
#include <iostream>

DoubleLinkedList::DoubleLinkedList() : front(nullptr), back(nullptr)
{
}

DoubleLinkedList::~DoubleLinkedList()
{
    while (!isEmpty())
    {
        Node *toDelete = front;
        front = front->next;
        delete toDelete;
    }
}

void DoubleLinkedList::add(int value)
{
    if (isEmpty())
        front = back = new Node(nullptr, value);
    else
        back->next = back = new Node(back, value);
}

bool DoubleLinkedList::remove(int value)
{
    Node *currentNode = front;

    while (currentNode != nullptr && currentNode->value != value)
        currentNode = currentNode->next;

    if (currentNode != nullptr)
    {
        if (currentNode->last == nullptr)
            front = currentNode->next;
        else
            currentNode->last->next = currentNode->next;

        if (currentNode->next == nullptr)
            back = currentNode->last;
        else
            currentNode->next->last = currentNode->last;

        delete currentNode;
        return true;
    }

    return false;
}

void DoubleLinkedList::removeAll(int value)
{
    Node *currentNode = front;

    while (currentNode != nullptr)
        if (currentNode->value == value)
        {
            if (currentNode->last == nullptr)
                front = currentNode->next;
            else
                currentNode->last->next = currentNode->next;

            if (currentNode->next == nullptr)
                back = currentNode->last;
            else
                currentNode->next->last = currentNode->last;

            Node *toDelete = currentNode;
            currentNode = currentNode->next;
            delete toDelete;
        }
        else
            currentNode = currentNode->next;
}

bool DoubleLinkedList::exists(int value)
{
    Node *currentNode = front;

    while (currentNode != nullptr && currentNode->value != value)
        currentNode = currentNode->next;

    return (currentNode != nullptr);
}

bool DoubleLinkedList::isEmpty()
{
    return front == nullptr;
}

void DoubleLinkedList::print()
{
    Node *currentNode = front;

    while (currentNode != nullptr)
    {
        std::cout << currentNode->value << " ";
        currentNode = currentNode->next;
    }
    std::cout << std::endl;
}

DoubleLinkedList::Node::Node(DoubleLinkedList::Node *lst, int val) : next(nullptr), last(lst), value(val)
{
}
