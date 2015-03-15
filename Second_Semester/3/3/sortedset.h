#pragma once
#include "icomparable.h"

/**
 * @brief The SortedSet class - the sorted set of IComparable descendants
 */
class SortedSet
{
public:
    SortedSet();
    ~SortedSet();

    /**
     * @brief add - adds new element to the set
     * @param obj - the object to add
     */
    void add(IComparable *obj);
    /**
     * @brief remove - removes element using the sample
     * @param obj - the sample
     */
    void remove(IComparable *obj);
    /**
     * @brief exists - checks if there is an element in the set.
     * @param obj - the sample of an element
     */
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
