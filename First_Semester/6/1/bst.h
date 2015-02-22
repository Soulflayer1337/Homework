#pragma once
#include <cstdio>

template <typename T>
struct BinarySearchTreeNode
{
    BinarySearchTreeNode<T> *left;
    BinarySearchTreeNode<T> *right;
    T value;
};

template <typename T>
struct BinarySearchTree
{
    BinarySearchTreeNode<T> *root;
};

/*
 * Create new Binary Search Tree.
 */
template <typename T>
BinarySearchTree<T> *createTree()
{
    BinarySearchTree<T> *tree = new BinarySearchTree<T>;
    tree->root = nullptr;
    return tree;
}

/*
 * Create new Node
 */
template <typename T>
BinarySearchTreeNode<T> *createNode(T value = T())
{
    BinarySearchTreeNode<T> *newNode = new BinarySearchTreeNode<T>;
    newNode->left = newNode->right = nullptr;
    newNode->value = value;
    return newNode;
}

/*
 * Delete tree
 */
template <typename T>
void deleteNode(BinarySearchTreeNode<T> **node)
{
    if (*node != nullptr)
    {
        deleteNode(&(*node)->left);
        deleteNode(&(*node)->right);
        delete (*node);
    }
}

template <typename T>
void deleteTree(BinarySearchTree<T> *tree)
{
    deleteNode(&tree->root);
    delete tree;
}

/*
 * Support function, used in some other functions
 */
template <typename T>
BinarySearchTreeNode<T> **findElement(BinarySearchTreeNode<T> **node, T value)
{
    if ((*node) != nullptr && (*node)->value != value)
    {
        if ((*node)->value > value)
            return findElement(&(*node)->left, value);
        else
            return findElement(&(*node)->right, value);
    }
    return node;
}

template <typename T>
BinarySearchTreeNode<T> **findElement(BinarySearchTree<T> *tree, T value)
{
    return findElement(&tree->root, value);
}

/*
 * Add new element in the tree. If element already exists, nothing well happen.
 */
template <typename T>
void addElement(BinarySearchTree<T> *tree, T value)
{
    BinarySearchTreeNode<T> **ptr = findElement(tree, value);

    if (*ptr == nullptr)
        *ptr = createNode(value);
}

/*
 * Functions used to remove elements
 */
template <typename T>
void removeWithOneOrLessChildren(BinarySearchTreeNode<T> **node)
{
    BinarySearchTreeNode<T> *child = ((*node)->left == nullptr ? (*node)->right : (*node)->left);
    delete (*node);
    (*node) = child;
}

template <typename T>
void removeWithBothChildren(BinarySearchTreeNode<T> **node)
{
    BinarySearchTreeNode<T> **currentNode = &(*node)->right;

    while ((*currentNode)->left != nullptr)
        currentNode = &(*currentNode)->left;

    (*node)->value = (*currentNode)->value;

    removeWithOneOrLessChildren(currentNode);
}

template <typename T>
void removeElement(BinarySearchTree<T> *tree, T value)
{
    BinarySearchTreeNode<T> **element = findElement(tree, value);

    if ((*element) == nullptr)
        return;

    if ((*element)->left != nullptr && (*element)->right != nullptr)
        removeWithBothChildren(element);
    else
        removeWithOneOrLessChildren(element);
}

/*
 * Find's element. If it exists.
 */
template <typename T>
bool exists(BinarySearchTree<T> *tree, T value)
{
    return ((*findElement(tree, value)) != nullptr);
}

/*
 * Functions to print out tree
 */

//Print Debug
template <typename T>
void printDebug(BinarySearchTreeNode<T> *node)
{
    if (node != nullptr)
    {
        printf("(%d ", node->value);
        printDebug(node->left);
        printDebug(node->right);
        printf(") ");
    }
    else
        printf("NULL ");
}

template <typename T>
void printDebug(BinarySearchTree<T> *tree)
{
    if (tree->root == nullptr)
        printf("Tree is empty!\n");
    else
        printDebug(tree->root);
}

//Print Ascending
template <typename T>
void printAscending(BinarySearchTreeNode<T> *node)
{
    if (node != nullptr)
    {
        printAscending(node->left);
        printf("%d ", node->value);
        printAscending(node->right);
    }
}

template <typename T>
void printAscending(BinarySearchTree<T> *tree)
{
    if (tree->root == nullptr)
        printf("Tree is empty!\n");
    else
        printAscending(tree->root);
}

//Print Descending
template <typename T>
void printDescending(BinarySearchTreeNode<T> *node)
{
    if (node != nullptr)
    {
        printDescending(node->right);
        printf("%d ", node->value);
        printDescending(node->left);
    }
}

template <typename T>
void printDescending(BinarySearchTree<T> *tree)
{
    if (tree->root == nullptr)
        printf("Tree is empty!\n");
    else
        printDescending(tree->root);
}
