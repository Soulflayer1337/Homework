#include "linkedstack.h"

LinkedStack::LinkedStack() : head(nullptr)
{
}

LinkedStack::~LinkedStack()
{
    while (!isEmpty())
        pop();
}

void LinkedStack::push(int value)
{
    head = new Node(value, head);
}

int LinkedStack::pop()
{
    if (isEmpty())
        return 0;

    Node *toRemove = head;
    head = head->next;
    int returnValue = toRemove->value;
    delete toRemove;
    return returnValue;
}

int LinkedStack::top()
{
    return (isEmpty() ? 0 : head->value);
}

bool LinkedStack::isEmpty() const
{
    return head == nullptr;
}


LinkedStack::Node::Node(int val, Node *nxt) : value(val), next(nxt)
{
}
