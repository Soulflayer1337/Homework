#pragma once
#include "stack.h"
#include <iostream>

class Calculator
{
public:
    Calculator();
    ~Calculator();

    int calculate(std::istream &stream, int &error);
    void setStack(Stack *stack);
private:
    Stack *stack;
};
