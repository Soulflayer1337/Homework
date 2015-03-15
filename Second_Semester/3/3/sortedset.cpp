#include "sortedset.h"

SortedSet::SortedSet() : first(new SetElement(nullptr, nullptr))
{
}

SortedSet::~SortedSet()
{
    SetElement *ptr = first;

    while (ptr != nullptr)
    {
        SetElement *toDelete = ptr;
        ptr = ptr->next;
        delete toDelete;
    }
}

void SortedSet::add(IComparable *obj)
{
    SetElement *ptr = first;

    while (ptr->next != nullptr && ptr->next->element->compareTo(obj) < 1)
    {
        if (ptr->next->element->isEqual(obj))
            return;
        ptr = ptr->next;
    }

    ptr->next = new SetElement(ptr->next, obj->copy());
}

void SortedSet::remove(IComparable *obj)
{
    SetElement *ptr = first;

    while (ptr->next != nullptr && ptr->next->element->compareTo(obj) < 1)
    {
        if (ptr->next->element->isEqual(obj))
        {
            SetElement *toDelete = ptr->next;
            ptr->next = toDelete->next;
            delete toDelete;
            break;
        }
        ptr = ptr->next;
    }
}

bool SortedSet::exists(const IComparable *obj) const
{
    SetElement *ptr = first->next;

    while (ptr != nullptr)
    {
        if (ptr->element->isEqual(obj))
            break;
        ptr = ptr->next;
    }
    return ptr != nullptr;
}



SortedSet::SetElement::SetElement(SortedSet::SetElement *nxt, IComparable *obj) : next(nxt), element(obj)
{
}

SortedSet::SetElement::~SetElement()
{
    if (element != nullptr)
        delete element;
}
