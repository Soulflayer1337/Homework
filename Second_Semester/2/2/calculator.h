#pragma once
#include "stack.h"

class Calculator
{
    Stack *stack;
public:
    Calculator();
    ~Calculator();

    void calculate();
    void setStack(Stack *stack);
};
