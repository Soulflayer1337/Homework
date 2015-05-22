#include "iterator.h"

Iterator::Iterator(BinTree *tree) : currentTree(tree), currentNode(nullptr)
{
    reset();
}

Iterator::~Iterator()
{
}

int Iterator::next()
{
    if (!currentNode)
        throw MissingElementException();

    int rValue = currentNode->object;

    if (currentNode->right)
    {
        currentNode = currentNode->right;

        while (currentNode->left)
            currentNode = currentNode->left;
    }
    else
    {
        while (currentNode->parent && (currentNode == currentNode->parent->right))
        {
            if (currentNode->parent == currentTree->root)
                currentNode = nullptr;

            currentNode = currentNode->parent;
        }
    }
    return rValue;
}

bool Iterator::isEmpty()
{
    return (currentNode == nullptr);
}

void Iterator::reset()
{
    BinTree::Node *leftMost = currentTree->root;

    if (!leftMost)
        return;

    while (leftMost->left)
        leftMost = leftMost->left;
}

void Iterator::remove()
{
    if (!currentNode)
        throw MissingElementException();

    BinTree::Node *prntNode = nullptr;

    if (currentNode->parent)
        prntNode = currentNode->parent;

    int value = currentNode->object;
    currentTree->remove(value);

    if (prntNode)
        currentNode = (value > prntNode->object ? prntNode->right : prntNode->left);
    else
        currentNode = currentTree->root;
}
