#pragma once
#include <iostream>

template <typename T>
struct Node
{
    T value;
    int height;
    Node<T> *left;
    Node<T> *right;
};

template <typename T>
struct Tree
{
    Node<T> *root;
};



/*
 * Support funcitons
 */
template <typename T>
int height(Node<T> *node)
{
    return (node != nullptr ? node->height : 0);
}

template <typename T>
int balanceFactor(Node<T> *node)
{
    return (node != nullptr ? height(node->right) - height(node->left) : 0);
}

template <typename T>
void updateHeight(Node<T> *node)
{
    int leftHeight = height(node->left);
    int rightHeight = height(node->right);
    node->height =  ((leftHeight > rightHeight) ? leftHeight : rightHeight) + 1;
}



/*
 * Rotation function
 */
template <typename T>
void leftRotate(Node<T> *&node)
{
    Node<T> *pivot = node->right;
    node->right = pivot->left;
    pivot->left = node;
    updateHeight(node);
    updateHeight(pivot);
    node = pivot;
}

template <typename T>
void rightRotate(Node<T> *&node)
{
    Node<T> *pivot = node->left;
    node->left = pivot->right;
    pivot->right = node;
    updateHeight(node);
    updateHeight(pivot);
    node = pivot;
}

template <typename T>
void balance(Node<T> *&node)
{
    if (node == nullptr)
        return;

    updateHeight(node);

    if (balanceFactor(node) == 2)
    {
        if (balanceFactor(node->right) < 0)
            rightRotate(node->right);

        leftRotate(node);
        return;
    }

    if (balanceFactor(node) == -2)
    {
        if (balanceFactor(node->left) > 0)
            leftRotate(node->left);

        rightRotate(node);
    }
}


/*
 * Functions to create a tree or node
 */
template <typename T>
Tree<T> *createTree()
{
    Tree<T> *tree = new Tree<T>;
    tree->root = nullptr;
    return tree;
}

template <typename T>
Node<T> *createNode(T value)
{
    Node<T> *node = new Node<T>;
    node->left = node->right = nullptr;
    node->height = 1;
    node->value = value;
    return node;
}

/*
 * Functions to delete a tree
 */
template <typename T>
void deleteNode(Node<T> *node)
{
    if (node == nullptr)
        return;

    deleteNode(node->left);
    deleteNode(node->right);
    delete node;
}

template <typename T>
void deleteTree(Tree<T> *tree)
{
    deleteNode(tree->root);
    delete tree;
}


/*
 * Functions to add/remove the elements.
 */
//Adding element.
template <typename T>
void addElement(Node<T> *&node, T value)
{
    if (node == nullptr)
    {
        node = createNode(value);
        return;
    }

    if (node->value == value)
    {
        return;
    }

    if (node->value > value)
        addElement(node->left, value);
    else
        addElement(node->right, value);

    balance(node);
}

template <typename T>
void addElement(Tree<T> *tree, T value)
{
    addElement(tree->root, value);
}

//Removing an element.
template <typename T>
void removeWithOneOrLessChildren(Node<T> *&node)
{
    Node<T> *child = (node->left == nullptr ? node->right : node->left);
    delete node;
    node = child;
}

template <typename T>
void removeWithBothChildren(Node<T> *&node)
{
    Node<T> *currentNode = node->right;

    while (currentNode->left != nullptr)
        currentNode = currentNode->left;

    node->value = currentNode->value;

    removeElement(node->right, node->value);
}

template <typename T>
void removeElement(Node<T> *&node, T value)
{
    if (node == nullptr)
        return;

    if (node->value == value)
    {
        if (node->left != nullptr && node->right != nullptr)
            removeWithBothChildren(node);
        else
            removeWithOneOrLessChildren(node);
    }
    else
        if (node->value > value)
            removeElement(node->left, value);
        else
            removeElement(node->right, value);

    balance(node);
}

template <typename T>
void removeElement(Tree<T> *tree, T value)
{
   removeElement(tree->root, value);
}

//Function checks if the element exists.
template <typename T>
bool exists(Node<T> *node, T value)
{
    if (node == nullptr)
        return false;

    if (node->value == value)
        return true;

    return exists(node->value > value ? node->left : node->right, value);
}

template <typename T>
bool exists(Tree<T> *tree, T value)
{
    return exists(tree->root, value);
}

/*
 * Print the contents of the tree
 */

//Set print function
template <typename T>
void setPrintFunction(Tree<T> *tree, void (*printFunction)(T))
{
    tree->printPtr = printFunction;
}


//Print the contents of the tree in the following form: (Parrent Left_Child Right_Child)
template <typename T>
void printDebug(Node<T> *node, std::ostream &stream)
{
    if (node == nullptr)
    {
        stream << "null";
        return;
    }

    stream << "(" << node->value << " ";
    printDebug(node->left, stream);
    stream << " ";
    printDebug(node->right, stream);
    stream << ")";
}

template <typename T>
void printDebug(Tree<T> *tree, std::ostream &stream = std::cout)
{
    printDebug(tree->root, stream);
    stream << "\n";
}


//Print the contents of the tree descending.
template <typename T>
void printDescending(Node<T> *node, std::ostream &stream)
{
    if (node == nullptr)
        return;

    printDescending(node->right, stream);

    stream << node->value << " ";

    printDescending(node->left, stream);
}

template <typename T>
void printDescending(Tree<T> *tree, std::ostream &stream = std::cout)
{
    printDescending(tree->root, stream);
    stream << "\n";
}


//Print the contents of the tree ascending.
template <typename T>
void printAscending(Node<T> *node, std::ostream &stream)
{
    if (node == nullptr)
        return;

    printAscending(node->left, stream);

    stream << node->value << " ";

    printAscending(node->right, stream);
}

template <typename T>
void printAscending(Tree<T> *tree, std::ostream &stream = std::cout)
{
    printAscending(tree->root, stream);
    stream << "\n";
}
