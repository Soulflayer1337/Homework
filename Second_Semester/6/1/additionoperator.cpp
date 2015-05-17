#include "additionoperator.h"
#include <iostream>

AdditionOperator::AdditionOperator(IOperand *leftOperand, IOperand *rightOperand) :
    Operator(leftOperand, rightOperand)
{
}

AdditionOperator::~AdditionOperator()
{
}

void AdditionOperator::print() const
{
    std::cout << "(+ ";
    left->print();
    std::cout << " ";
    right->print();
    std::cout << ")";
}

ll AdditionOperator::count() const
{
    return (left->count() + right->count());
}


