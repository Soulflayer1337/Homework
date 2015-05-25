#include "list.h"
#include <iostream>

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

void List::add(const std::string &addValue)
{
    guard->next = new Node(guard->next, addValue);
    length++;
}

bool List::exists(const std::string &value) const
{
    Node *ptr = guard->next;

    while (ptr && (ptr->string != value))
        ptr = ptr->next;

    return ptr;
}

void List::remove(const std::string &value)
{
    Node *ptr = guard;

    while (ptr->next && (ptr->next->string != value))
        ptr = ptr->next;

    if (ptr->next)
    {
        Node *toDelete = ptr->next;
        ptr->next = toDelete->next;
        delete toDelete;
        length--;
    }
    else
        throw MissingElementException();
}

std::string List::pop()
{
    if (isEmpty())
        throw MissingElementException();

    Node *toDelete = guard->next;
    std::string topElement = toDelete->string;
    guard->next = toDelete->next;
    delete toDelete;
    length--;

    return topElement;
}

unsigned int List::getLength() const
{
    return length;
}

bool List::isEmpty() const
{
    return !length;
}

List::Node::Node() : Node(nullptr, "")
{
}

List::Node::Node(List::Node *nxt, const std::string example) : next(nxt), string(example)
{
}

List::Node::~Node()
{
}
