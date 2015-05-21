#pragma once
#include "../../../Some_Useful_Things/Exceptions/missingelement.h"

/// @brief The List class - just the list
class List
{
public:
    List();
    ~List();

    /// @brief add - adds new element in the list
    void add(int value);
    /// @brief remove - removes element or throws the exception
    void remove(int value);
    /// @brief exists - checks if the element exists
    bool exists(int value) const;
    /// @brief getLength - returns the number of elements
    int getLength() const;
    /// @brief isEmpty - checks if the list is empty
    bool isEmpty() const;
protected:
    class Node
    {
    public:
        Node(int val = 0, Node *nxt = nullptr);
        Node *next;
        int value;
    } *guard;

    /**
     * @brief findElement - support function for exists-function and remove-function
     * @return the Node that points at the element with the same value as the value passed to the function
     */
    Node *findElement(int value) const;
    int length;
};
