#pragma once
#include "stack.h"

class LinkedStack : public Stack
{
public:
    LinkedStack();
    ~LinkedStack();
    void push(int value);
    int pop();
    int top();
    bool isEmpty() const;
private:
    struct Node
    {
        Node *next;
        int value;
        Node(int val, Node *nxt);
    } *head;
};
