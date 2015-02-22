#include "tree_queue.h"

struct Node
{
    Pair<int, int> *value;
    int height;
    Node *left;
    Node *right;
};

struct TreeQueue
{
    Node *root;
};

void removeElement(Node *&node, Pair<int, int> *value);


/*
 * Support funcitons
 */
int height(Node *node)
{
    return (node != nullptr ? node->height : 0);
}

int balanceFactor(Node *node)
{
    return (node != nullptr ? height(node->right) - height(node->left) : 0);
}

void updateHeight(Node *node)
{
    int leftHeight = height(node->left);
    int rightHeight = height(node->right);
    node->height =  ((leftHeight > rightHeight) ? leftHeight : rightHeight) + 1;
}



/*
 * Rotation function
 */
void leftRotate(Node *&node)
{
    Node *pivot = node->right;
    node->right = pivot->left;
    pivot->left = node;
    updateHeight(node);
    updateHeight(pivot);
    node = pivot;
}

void rightRotate(Node *&node)
{
    Node *pivot = node->left;
    node->left = pivot->right;
    pivot->right = node;
    updateHeight(node);
    updateHeight(pivot);
    node = pivot;
}

void balance(Node *&node)
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
TreeQueue *createTree()
{
    TreeQueue *tree = new TreeQueue;
    tree->root = nullptr;
    return tree;
}

Node *createNode(Pair<int, int> *value)
{
    Node *node = new Node;
    node->left = node->right = nullptr;
    node->height = 1;
    node->value = value;
    return node;
}



/*
 * Functions to delete a tree
 */
void deleteNode(Node *node)
{
    if (node == nullptr)
        return;

    deleteNode(node->left);
    deleteNode(node->right);
    delete node;
}

void deleteTree(TreeQueue *tree)
{
    deleteNode(tree->root);
    delete tree;
}



/*
 * Functions to add/remove the elements.
 */
//Adding element.
void addElement(Node *&node, Pair<int, int> *value)
{
    if (node == nullptr)
    {
        node = createNode(value);
        return;
    }

    if (node->value->first == value->first && node->value->second == value->second)
        return;

    if (node->value->first > value->first)
        addElement(node->left, value);
    else
        addElement(node->right, value);

    balance(node);
}

void push(TreeQueue *tree, Pair<int, int> *value)
{
    addElement(tree->root, value);
}

void removeWithOneOrLessChildren(Node *&node)
{
    Node *child = (node->left == nullptr ? node->right : node->left);
    delete node;
    node = child;
}

void removeWithBothChildren(Node *&node)
{
    Node *currentNode = node->right;

    while (currentNode->left != nullptr)
        currentNode = currentNode->left;

    node->value = currentNode->value;

    removeElement(node->right, node->value);
}

void removeElement(Node *&node, Pair<int, int> *value)
{
    if (node == nullptr)
        return;

    if ((node->value->first == value->first) && (node->value->second == value->second))
    {
        if (node->left != nullptr && node->right != nullptr)
            removeWithBothChildren(node);
        else
            removeWithOneOrLessChildren(node);
    }
    else
        if (node->value->first > value->first)
            removeElement(node->left, value);
        else
            removeElement(node->right, value);

    balance(node);
}

void removeElement(TreeQueue *tree, Pair<int, int> *value)
{
   removeElement(tree->root, value);
}

Pair<int, int> *pop(Node *&node)
{
    Pair<int, int> *returnValue = nullptr;
    if (node->left == nullptr)
    {
        Node *child = node->right;
        returnValue = makePair(node->value);
        delete node->value;
        delete node;
        node = child;
    }
    else
        returnValue = pop(node->left);

    balance(node);
    return returnValue;
}

Pair<int, int> *pop(TreeQueue *tree)
{
    Node *currentNode = tree->root;
    while (currentNode->left != nullptr)
        currentNode = currentNode->left;
    return pop(tree->root);
}


bool isEmpty(TreeQueue *tree)
{
    return (tree->root == nullptr);
}


void printQueue(Node *node)
{
    if (node == nullptr)
        return;
    std::cout << "(";
    printQueue(node->left);
    std::cout << "<" << node->value->first << " " << node->value->second << "> ";
    printQueue(node->right);
    std::cout << ") ";
}

void printQueue(TreeQueue *tree)
{
    printQueue(tree->root);
    std::cout << std::endl;
}
