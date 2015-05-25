#pragma once
#include <iostream>

class MissingElementException{};

/**
 * @brief The List class - the list
 */
class List
{
public:
    List();
    ~List();

    /**
     * @brief add - adds new element
     */
    void add(const std::string &value);
    /**
     * @brief exists - checks if the element exists
     */
    bool exists(const std::string &value) const;
    /**
     * @brief remove - removes the element if it exists, otherwise throws an exception .
     */
    void remove(const std::string &value);
    /**
     * @brief pop - removes the first element from the list
     * @return returns the pointer to that element
     */
    std::string pop();
    /**
     * @brief getLength - returns the number of element in the list
     */
    unsigned int getLength() const;
    /**
     * @brief isEmpty - checks if the list is empty
     */
    bool isEmpty() const;
private:
    class Node
    {
    public:
        Node();
        Node(Node *nxt, const std::string example);
        ~Node();
        Node *next;
        const std::string string;
    } *guard;

    /**
     * @brief length - the number of elements in the list
     */
    unsigned int length;
};
