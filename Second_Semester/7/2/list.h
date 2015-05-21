#pragma once
#include "../../../Some_Useful_Things/Exceptions/missingelement.h"

class List
{
public:
    List();
    ~List();

    void add(int value);
    void remove(int value);
    bool exists(int value) const;
    int getLength() const;
    bool isEmpty() const;
protected:
    class Node
    {
    public:
        Node(int val = 0, Node *nxt = nullptr);
        Node *next;
        int value;
    } *guard;

    Node *findElement(int value) const;
    int length;
};
