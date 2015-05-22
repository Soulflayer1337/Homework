#include "bintree.h"

BinTree::BinTree() : root(nullptr)
{
}

BinTree::~BinTree()
{
    delete root;
}

void BinTree::add(const int value)
{
    add(nullptr, root, value);
}

void BinTree::remove(const int value)
{
    remove(root, value);
}

bool BinTree::exists(const int value) const
{
    Node *ptr = root;

    while (ptr && ptr->object != value)
        if (ptr->object < value)
            ptr = ptr->right;
        else
            ptr = ptr->left;

    return (ptr != nullptr);
}

bool BinTree::isEmpty() const
{
    return (root == nullptr);
}

void BinTree::removeWithTwo(BinTree::Node *&currentNode)
{
    Node *leftMost = currentNode->right;

    while (leftMost->left)
        leftMost = leftMost->left;

    currentNode->object = leftMost->object;
    remove(currentNode->right, currentNode->object);
}

void BinTree::removeOneOrLess(BinTree::Node *&currentNode, Node *&childNode)
{
    if (childNode)
        childNode->parent = currentNode->parent;

    Node *toDelete = currentNode;
    currentNode = childNode;
    childNode = nullptr;
    delete toDelete;
}

void BinTree::add(BinTree::Node *parent, BinTree::Node *&currentNode, const int value)
{
    if (currentNode == nullptr)
    {
        currentNode = new Node(value, parent);
        return;
    }

    if (currentNode->object == value)
        throw ElementExistsException();

    if (currentNode->object > value)
        add(currentNode, currentNode->left, value);
    else if (currentNode->object < value)
        add(currentNode, currentNode->right, value);
}

void BinTree::remove(BinTree::Node *&currentNode, const int value)
{
    if (!currentNode)
        throw MissingElementException();

    if (currentNode->object == value)
    {
        if (currentNode->left && currentNode->right)
            removeWithTwo(currentNode);
        else if (currentNode->left == nullptr)
            removeOneOrLess(currentNode, currentNode->right);
        else
            removeOneOrLess(currentNode, currentNode->left);
    }
    else if (currentNode->object > value)
        remove(currentNode->left, value);
    else
        remove(currentNode->right, value);
}

BinTree::Node::Node(int obj, Node *prnt) : right(nullptr), left(nullptr), parent(prnt), object(obj)
{
}

BinTree::Node::~Node()
{
    if (left)
        delete left;
    if (right)
        delete right;
}

