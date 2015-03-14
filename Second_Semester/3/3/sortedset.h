#pragma once
#include "icomparable.h"

class SortedSet
{
public:
    SortedSet();
    ~SortedSet();

    void add(IComparable *obj);
    void remove(IComparable *obj);
    bool exists(const IComparable *obj) const;
private:
    struct SetElement
    {
        SetElement(SetElement *nxt, IComparable *obj);
        ~SetElement();

        SetElement *next;
        IComparable *element;
    } *first;
};
