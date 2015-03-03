#pragma once
#include "stack.h"

class ArrayStack : public Stack
{
public:
    ArrayStack();
    ~ArrayStack();
    void push(int value);
    int pop();
    int top();
    bool isEmpty() const;
private:
    int capacity;
    int size;
    int *array;
};
