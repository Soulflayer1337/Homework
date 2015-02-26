#pragma once
#include "stack.h"

class LinkedStack : public Stack
{
    struct Node
    {
        Node *next;
        int value;
        Node(int val, Node *nxt);
    } *head;
public:
    LinkedStack();
    ~LinkedStack();
    void push(int value);
    int pop();
    int top();
    bool isEmpty() const;
};
