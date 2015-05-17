#pragma once
#include <iostream>

class MissingElementException
{
};

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
    /// \brief setIntersection - creates new set obtained by intersection of two sets
    Set *setIntersection(Set *set);
    /// \brief setUnion - creates new set obtained by union of two sets
    Set *setUnion(Set *set);

    /// \brief getArray - creates array containing the elements of the set
    T *getArray(int &sizeOfArray);
    /// \brief printTree - prints Tree with the elements in the nodes
    void printTree();
private:
    int setSize;
    struct Node
    {
        Node(const T &obj);
        ~Node();
        Node *left;
        Node *right;
        int height;
        T object;
    } *root;

    // The following are just the support functions
    void getArray(Node *currentNode, T *array, int &iterator);
    void printTree(Node *node);
    void add(Node *&currentNode, const T &obj);
    void remove(Node *&currentNode, const T &obj);
    bool exists(Node *currentNode, const T &obj) const;

    void oneOrLessChildren(Node *&currentNode, Node *toChange);
    void twoChildren(Node *&currentNode);

    int height(Node *currentNode);
    void updateHeight(Node *currentNode);
    int balanceFactor(Node *currentNode);

    void rotateRight(Node *&currentNode);
    void rotateLeft(Node *&currentNode);
    void balance(Node *&currentNode);
};

template <typename T>
Set<T>::Set() : setSize(0), root(nullptr)
{
}

template <typename T>
Set<T>::~Set()
{
    if (root)
        delete root;
}

template <typename T>
void Set<T>::add(const T obj)
{
    add(root, obj);
}

template <typename T>
void Set<T>::remove(const T obj)
{
    remove(root, obj);
    setSize--;
}

template <typename T>
bool Set<T>::exists(const T obj) const
{
    return exists(root, obj);
}

template <typename T>
bool Set<T>::isEmpty() const
{
    return (root == nullptr);
}

template <typename T>
T *Set<T>::getArray(int &sizeOfArray)
{
    sizeOfArray = setSize;
    T *array = new T[sizeOfArray];
    int iterator = 0;
    getArray(root, array, iterator);
    return array;
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

template <typename T>
void Set<T>::printTree()
{
    std::cout << "Status:\n";
    printTree(root);
    std::cout << "\n\n";
}

template <typename T>
void Set<T>::getArray(Node *currentNode, T *array, int &iterator)
{
    if (currentNode->left)
        getArray(currentNode->left, array, iterator);

    array[iterator++] = currentNode->object;

    if (currentNode->right)
        getArray(currentNode->right, array, iterator);
}

template <typename T>
void Set<T>::printTree(Node *node)
{
    if (!node)
    {
        std::cout << "X";
        return;
    }

    std::cout << "(";
    std::cout << node->object << " ";
    printTree(node->left);
    std::cout << " ";
    printTree(node->right);
    std::cout << ")";
}

template <typename T>
void Set<T>::add(Node *&currentNode, const T &obj)
{
    if (!currentNode)
    {
        setSize++;
        currentNode = new Node(obj);
        return;
    }

    if (obj > currentNode->object)
        add(currentNode->right, obj);

    if (obj < currentNode->object)
        add(currentNode->left, obj);

    balance(currentNode);
}

template <typename T>
void Set<T>::remove(Node *&currentNode, const T &obj)
{
    if (!currentNode)
        throw MissingElementException();

    if (currentNode->object == obj)
    {
        if (!currentNode->right)
            oneOrLessChildren(currentNode, currentNode->left);
        else if (!currentNode->left)
            oneOrLessChildren(currentNode, currentNode->right);
        else
            twoChildren(currentNode);
    }
    else
        if (currentNode->object < obj)
            remove(currentNode->right, obj);
        else
            remove(currentNode->left, obj);

    balance(currentNode);
}

template <typename T>
bool Set<T>::exists(Node *currentNode, const T &obj) const
{
    if (!currentNode)
        return false;

    if (obj == currentNode->object)
        return true;

    return (obj < currentNode->object ? exists(currentNode->left, obj) : exists(currentNode->right, obj));
}

template <typename T>
void Set<T>::oneOrLessChildren(Node *&currentNode, Node *toChange)
{
    currentNode->left = currentNode->right = nullptr;
    delete currentNode;
    currentNode = toChange;
}

template <typename T>
void Set<T>::twoChildren(Node *&currentNode)
{
    Node *leftmost = currentNode->right;

    while (leftmost->left)
        leftmost = leftmost->left;

    currentNode->object = leftmost->object;

    remove(currentNode->right, currentNode->object);
}

template <typename T>
int Set<T>::height(Node *currentNode)
{
    return (currentNode ? currentNode->height : 0);
}

template <typename T>
void Set<T>::updateHeight(Node *currentNode)
{
    if (!currentNode)
        return;

    int heightLeft = height(currentNode->left);
    int heightRight = height(currentNode->right);
    currentNode->height = (heightLeft < heightRight ? heightRight : heightLeft) + 1;
}

template <typename T>
int Set<T>::balanceFactor(Node *currentNode)
{
    return (currentNode ? height(currentNode->right) - height(currentNode->left) : 0);
}

template <typename T>
void Set<T>::rotateRight(Node *&currentNode)
{
    Node *ptr = currentNode->left;
    currentNode->left = ptr->right;
    ptr->right = currentNode;
    updateHeight(currentNode);
    updateHeight(ptr);
    currentNode = ptr;
}

template <typename T>
void Set<T>::rotateLeft(Node *&currentNode)
{
    Node *ptr = currentNode->right;
    currentNode->right = ptr->left;
    ptr->left = currentNode;
    updateHeight(currentNode);
    updateHeight(ptr);
    currentNode = ptr;
}

template <typename T>
void Set<T>::balance(Node *&currentNode)
{
    updateHeight(currentNode);

    if (balanceFactor(currentNode) == 2)
    {
        if (balanceFactor(currentNode->right) < 0)
            rotateRight(currentNode->right);

        rotateLeft(currentNode);
    }
    else if (balanceFactor(currentNode) == -2)
    {
        if (balanceFactor(currentNode->left) > 0)
            rotateLeft(currentNode->left);

        rotateRight(currentNode);
    }
}

template <typename T>
Set<T>::Node::Node(const T &obj) : left(nullptr), right(nullptr), height(1), object(obj)
{
}

template <typename T>
Set<T>::Node::~Node()
{
    if (left)
        delete left;
    if (right)
        delete right;
}
