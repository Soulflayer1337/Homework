#pragma once
#include <avltree.h>

/// \brief The Set class - template set class that provides us with union & intersection functions
template <typename T>
class Set
{
public:
    Set();
    ~Set();

    /// \brief add - adds new element
    void add(const T obj);
    /// \brief remove - removes element
    void remove(const T obj);
    /// \brief exists - checks if the element exists
    bool exists(const T obj) const;
    /// \brief isEmpty - checks if set is empty
    bool isEmpty() const;
    /// \brief getArray - creates array containing the elements of the set
    T *getArray(int &sizeOfArray);
    /// \brief setIntersection - creates new set obtained by intersection of two sets
    Set *setIntersection(Set *set);
    /// \brief setUnion - creates new set obtained by union of two sets
    Set *setUnion(Set *set);
private:
    AVLTree<T> *contains;
};

template <typename T>
Set<T>::Set() : contains(new AVLTree<T>)
{
}

template <typename T>
Set<T>::~Set()
{
    delete contains;
}

template <typename T>
void Set<T>::add(const T obj)
{
    contains->add(obj);
}

template <typename T>
void Set<T>::remove(const T obj)
{
    contains->remove(obj);
}

template <typename T>
bool Set<T>::exists(const T obj) const
{
    return contains->exists(obj);
}

template <typename T>
bool Set<T>::isEmpty() const
{
    return contains->isEmpty();
}

template <typename T>
T *Set<T>::getArray(int &sizeOfArray)
{
    return contains->getArray(sizeOfArray);
}

template <typename T>
Set<T> *Set<T>::setUnion(Set<T> *set)
{
    int sizeOfArray = 0;
    T *array = getArray(sizeOfArray);
    Set<T> *newSet = new Set<T>;

    for (int i = 0; i < sizeOfArray; i++)
        newSet->add(array[i]);

    delete array;

    array = set->getArray(sizeOfArray);

    for (int i = 0; i < sizeOfArray; i++)
        newSet->add(array[i]);

    delete array;
    return newSet;
}

template <typename T>
Set<T> *Set<T>::setIntersection(Set<T> *set)
{
    int firstSize = 0;
    T *firstArray = getArray(firstSize);

    int secondSize = 0;
    T *secondArray = set->getArray(secondSize);

    int firstIt = 0;
    int secondIt = 0;

    Set<T> *newSet = new Set<T>;

    while (firstIt < firstSize && secondIt < secondSize)
    {
        if (firstArray[firstIt] == secondArray[secondIt])
        {
            newSet->add(firstArray[firstIt]);
            firstIt++;
            secondIt++;
        }
        else if (firstArray[firstIt] < secondArray[secondIt])
            firstIt++;
        else
            secondIt++;
    }

    delete firstArray;
    delete secondArray;
    return newSet;
}
