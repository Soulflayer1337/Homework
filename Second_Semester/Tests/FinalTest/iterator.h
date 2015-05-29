#pragma once
#include "bintree.h"

/// \brief The Iterator class - the iterator class for BinTree class
class Iterator
{
public:
    Iterator(BinTree *tree);
    ~Iterator();

    /// \brief next - returns value of the currentNode and goes to next element, or throws exception
    int next();
    /// \brief isEmpty - returns true if last next() returned the last element of the tree
    bool isEmpty();
    /// \brief reset - starts point to the first element
    void reset();
    /// \brief remove - removes current element, or throws exception
    void remove();
private:
    BinTree *currentTree;
    BinTree::Node *currentNode;
};
