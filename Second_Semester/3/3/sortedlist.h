#pragma once
#include "icomparable.h"

class SortedList : public IComparable
{
public:
    SortedList();
    ~SortedList();
    int compareTo(const IComparable *obj) const;
    bool isEqual(const IComparable *obj) const;

    void add(const int value);
    void remove(const int value);
    void removeAll(const int value);
    IComparable *copy() const;

    bool exists(int value) const;
    int count(int value) const;
    int count() const;
    int *convertToArray() const;

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
