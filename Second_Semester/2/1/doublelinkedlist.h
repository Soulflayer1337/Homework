#pragma once
#include "list.h"

class DoubleLinkedList : public List
{
public:
    DoubleLinkedList();
    ~DoubleLinkedList();
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
        Node *last;
        int value;
        Node(Node *lst, int val);
    };
    Node *front;
    Node *back;
};
