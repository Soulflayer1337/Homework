#pragma once
#include "stack.h"

class Calculator
{
public:
    Calculator();
    ~Calculator();

    void calculate();
    void setStack(Stack *stack);
private:
    Stack *stack;
};
