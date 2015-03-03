#pragma once
#include "list.h"

class SortedList : public List
{
public:
    SortedList();
    ~SortedList();
    void add(int value);
    bool remove(int value);
    void removeAll(int value);
    bool exists(int value);
    bool isEmpty();
    void print();
private:
    struct Node
    {
        Node *next;
        int value;
        Node(Node *nxt, int val);
    } *first;
};
