#pragma once
class Iterator;

class MissingElementException
{
};

class ElementExistsException
{
};

/// \brief The BinTree class - the class for tree
class BinTree
{
public:
    friend class Iterator;

    BinTree();
    ~BinTree();

    void add(const int value);
    void remove(const int value);
    bool exists(const int value) const;
    bool isEmpty() const;
protected:
    class Node
    {
    public:
        Node(int obj, Node *prnt);
        ~Node();
        Node *right;
        Node *left;
        Node *parent;
        int object;
    } *root;
    void removeOneOrLess(Node *&currentNode, Node *&childNode);
    void removeWithTwo(Node *&currentNode);

    void add(Node *parent, Node *&currentNode, const int value);
    void remove(Node *&currentNode, const int value);
};

#include "iterator.h"
