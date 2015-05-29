#pragma once

class MissingElementException
{
};

/// \brief The AVLTree class - template tree class, which can store the same elements
template <typename T>
class AVLTree
{
public:
    AVLTree();
    ~AVLTree();

    /// \brief add - adds an element
    void add(const T obj);
    /// \brief remove - removes an element
    void remove(const T obj);
    /// \brief exists - checks if the element exists
    bool exists(const T obj) const;
    /// \brief numberOfElements - counts the number of elements
    int numberOfElements(const T obj) const;
    /// \brief isEmpty - checks if tree is empty
    bool isEmpty() const;
private:
    struct Node
    {
        Node(const T &obj);
        ~Node();
        Node *left;
        Node *right;
        int height;
        T object;
        int number;
    } *root;

    // The following are just the support functions
    void add(Node *&currentNode, const T &obj);
    void remove(Node *&currentNode, const T &obj);
    int numberOfElements(Node *currentNode, const T &obj) const;

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
AVLTree<T>::AVLTree() : root(nullptr)
{
}

template <typename T>
AVLTree<T>::~AVLTree()
{
    if (root)
        delete root;
}

template <typename T>
void AVLTree<T>::add(const T obj)
{
    add(root, obj);
}

template <typename T>
void AVLTree<T>::remove(const T obj)
{
    remove(root, obj);
}

template <typename T>
bool AVLTree<T>::exists(const T obj) const
{
    return (numberOfElements(root, obj) != 0);
}

template <typename T>
int AVLTree<T>::numberOfElements(const T obj) const
{
    return numberOfElements(root, obj);
}

template <typename T>
bool AVLTree<T>::isEmpty() const
{
    return (root == nullptr);
}

template <typename T>
void AVLTree<T>::add(Node *&currentNode, const T &obj)
{
    if (!currentNode)
    {
        currentNode = new Node(obj);
        return;
    }

    if (obj > currentNode->object)
        add(currentNode->right, obj);
    else if (obj < currentNode->object)
        add(currentNode->left, obj);
    else
        currentNode->number++;

    balance(currentNode);
}

template <typename T>
void AVLTree<T>::remove(Node *&currentNode, const T &obj)
{
    if (!currentNode)
        throw MissingElementException();

    if (currentNode->object == obj)
    {
        if (currentNode->number > 1)
            currentNode->number--;
        else if (!currentNode->right)
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
int AVLTree<T>::numberOfElements(Node *currentNode, const T &obj) const
{
    if (!currentNode)
        return 0;

    if (obj == currentNode->object)
        return currentNode->number;

    return (obj < currentNode->object ? numberOfElements(currentNode->left, obj) : numberOfElements(currentNode->right, obj));
}

template <typename T>
void AVLTree<T>::oneOrLessChildren(Node *&currentNode, Node *toChange)
{
    currentNode->left = currentNode->right = nullptr;
    delete currentNode;
    currentNode = toChange;
}

template <typename T>
void AVLTree<T>::twoChildren(Node *&currentNode)
{
    Node *leftmost = currentNode->right;

    while (leftmost->left)
        leftmost = leftmost->left;

    currentNode->object = leftmost->object;

    remove(currentNode->right, currentNode->object);
}

template <typename T>
int AVLTree<T>::height(Node *currentNode)
{
    return (currentNode ? currentNode->height : 0);
}

template <typename T>
void AVLTree<T>::updateHeight(Node *currentNode)
{
    if (!currentNode)
        return;

    int heightLeft = height(currentNode->left);
    int heightRight = height(currentNode->right);
    currentNode->height = (heightLeft < heightRight ? heightRight : heightLeft) + 1;
}

template <typename T>
int AVLTree<T>::balanceFactor(Node *currentNode)
{
    return (currentNode ? height(currentNode->right) - height(currentNode->left) : 0);
}

template <typename T>
void AVLTree<T>::rotateRight(Node *&currentNode)
{
    Node *ptr = currentNode->left;
    currentNode->left = ptr->right;
    ptr->right = currentNode;
    updateHeight(currentNode);
    updateHeight(ptr);
    currentNode = ptr;
}

template <typename T>
void AVLTree<T>::rotateLeft(Node *&currentNode)
{
    Node *ptr = currentNode->right;
    currentNode->right = ptr->left;
    ptr->left = currentNode;
    updateHeight(currentNode);
    updateHeight(ptr);
    currentNode = ptr;
}

template <typename T>
void AVLTree<T>::balance(Node *&currentNode)
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
AVLTree<T>::Node::Node(const T &obj) : left(nullptr), right(nullptr), height(1), object(obj), number(1)
{
}

template <typename T>
AVLTree<T>::Node::~Node()
{
    if (left)
        delete left;
    if (right)
        delete right;
}
