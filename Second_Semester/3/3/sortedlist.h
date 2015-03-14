#pragma once
#include "icomparable.h"

/**
 * @brief The SortedList class - SortedList, able to be compared
 */
class SortedList : public IComparable
{
public:
    SortedList();
    ~SortedList();
    int compareTo(const IComparable *obj) const;
    bool isEqual(const IComparable *obj) const;

    /**
     * @brief add - adds an element to the list
     */
    void add(const int value);
    /**
     * @brief remove - removes one element from the list
     * @param value - the value of an element to remove
     */
    void remove(const int value);
    /**
     * @brief removeAll - removes all items from the list
     * @param value - the value of an element to remove
     */
    void removeAll(const int value);

    IComparable *copy() const;
    /**
     * @brief exists - checks if there is an element in the list
     * @param value - value of an element in the list
     */
    bool exists(int value) const;
    /**
     * @brief count - counts number of elements in the list
     * @param value - the sample of an element to count
     */
    int count(int value) const;
    /**
     * @brief count - counts number of all elements in the list
     */
    int count() const;
    /**
     * @brief convertToArray - converts the contents of the list into an array
     */
    int *convertToArray() const;

    /**
     * @brief print - prints elements of the list
     */
    void print() const;
protected:
    int numberOfElements;

    struct Node
    {
        Node(Node *nxt, int val);
        Node *next;
        int value;
    } *head;
};
