#include "multiplicationoperator.h"
#include <iostream>

MultiplicationOperator::MultiplicationOperator(IOperand *leftOperand, IOperand *rightOperand) : Operator(leftOperand, rightOperand)
{
}

MultiplicationOperator::~MultiplicationOperator()
{
}

void MultiplicationOperator::print() const
{
    std::cout << "(* ";
    left->print();
    std::cout << " ";
    right->print();
    std::cout << ")";
}

ll MultiplicationOperator::count() const
{
    return (left->count() * right->count());
}

