#pragma once
#include "ioperand.h"
#include <iostream>
#include "../../../Some_Useful_Things/Exceptions/dividedbyzero.h"

/// @brief The ExpressionParser class - the class that provides us with parser.
class ExpressionParser
{
public:
    ExpressionParser();
    ~ExpressionParser();

    /**
     * @brief parse - parses the expression from the stream(string)
     */
    static IOperand *parse(std::istream &stream);
    static IOperand *parse(const std::string &expression);
    static IOperand *parse(const std::string &expression, int &index);
private:
    static IOperand *newOperator(char operation, IOperand *leftOperand, IOperand *rightOperand);
    static void ignoreSpaces(std::istream &stream);
    static void ignoreSpaces(const std::string &expression, int &index);
};
