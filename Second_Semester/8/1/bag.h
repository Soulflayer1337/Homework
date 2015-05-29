#pragma once
#include "AVLTree.h"

template <typename T>
class Bag
{
public:
    Bag();
    ~Bag();

    /// \brief add - adds an element
    void add(const T obj);
    /// \brief remove - removes an element
    void remove(const T obj);
    /// \brief exists - checks if the element exists
    bool exists(const T obj) const;
    /// \brief numberOfElements - counts the number of elements
    int numberOfElements(const T obj) const;
    /// \brief isEmpty - checks if bag is empty
    bool isEmpty() const;
private:
    AVLTree<T> *avlTree;
};

template <typename T>
Bag<T>::Bag() : avlTree(new AVLTree<T>)
{
}

template <typename T>
Bag<T>::~Bag()
{
    delete avlTree;
}

template <typename T>
void Bag<T>::add(const T obj)
{
    avlTree->add(obj);
}

template <typename T>
void Bag<T>::remove(const T obj)
{
    avlTree->remove(obj);
}

template <typename T>
bool Bag<T>::exists(const T obj) const
{
    return avlTree->exists(obj);
}

template <typename T>
int Bag<T>::numberOfElements(const T obj) const
{
    return avlTree->numberOfElements(obj);
}

template <typename T>
bool Bag<T>::isEmpty() const
{
    return avlTree->isEmpty();
}
