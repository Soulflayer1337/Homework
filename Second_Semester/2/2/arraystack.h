#pragma once
#include "stack.h"

class ArrayStack : public Stack
{
    int capacity;
    int size;
    int *array;
public:
    ArrayStack();
    ~ArrayStack();
    void push(int value);
    int pop();
    int top();
    bool isEmpty() const;
};
