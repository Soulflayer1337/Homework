#include "list.h"

List::List() : guard(new Node), length(0)
{
}

List::~List()
{
    while (guard)
    {
        Node *toDelete = guard;
        guard = guard->next;
        delete toDelete;
    }
}

void List::add(int value)
{
    guard->next = new Node(value, guard->next);
    length++;
}

void List::remove(int value)
{
    Node *previous = findElement(value);

    if (previous == nullptr)
        throw MissingElementException();

    Node *toDelete = previous->next;
    previous->next = toDelete->next;
    delete toDelete;
    length--;
}

bool List::exists(int value) const
{
    return (findElement(value) != nullptr);
}

int List::getLength() const
{
    return length;
}

bool List::isEmpty() const
{
    return (guard->next == nullptr);
}

List::Node *List::findElement(int value) const
{
    Node *previous = guard;

    while (previous->next && previous->next->value != value)
        previous = previous->next;

    return (previous->next ? previous : nullptr);
}


List::Node::Node(int val, List::Node *nxt) : next(nxt), value(val)
{
}
