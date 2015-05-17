#include "operator.h"
#include <iostream>

Operator::Operator(IOperand *leftOperand, IOperand *rightOperand) : left(leftOperand), right(rightOperand)
{
}

Operator::~Operator()
{
    delete left;
    delete right;
}
