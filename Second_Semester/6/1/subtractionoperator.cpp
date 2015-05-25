#include "subtractionoperator.h"
#include <iostream>

SubtractionOperator::SubtractionOperator(IOperand *leftOperand, IOperand *rightOperand) : Operator(leftOperand, rightOperand)
{
}

SubtractionOperator::~SubtractionOperator()
{
}

void SubtractionOperator::print() const
{
    std::cout << "(- ";
    left->print();
    std::cout << " ";
    right->print();
    std::cout << ")";
}

ll SubtractionOperator::count() const
{
    return (left->count() - right->count());
}

