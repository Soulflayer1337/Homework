#include "expressionparser.h"
#include "operand.h"
#include "additionoperator.h"
#include "subtractionoperator.h"
#include "multiplicationoperator.h"
#include "divisionoperator.h"

ExpressionParser::ExpressionParser()
{
}

ExpressionParser::~ExpressionParser()
{
}

IOperand *ExpressionParser::parse(std::istream &stream)
{
    ignoreSpaces(stream);

    if (std::isdigit(stream.peek()))
    {
        ll number = 0;
        stream >> number;
        return new Operand(number);
    }

    stream.ignore();
    char operation = stream.get();

    IOperand *leftOperand = parse(stream);
    IOperand *rightOperand = parse(stream);
    IOperand *returnValue = nullptr;

    ignoreSpaces(stream);
    stream.ignore();

    switch (operation)
    {
    case '+':
    {
        returnValue = new AdditionOperator(leftOperand, rightOperand);
        break;
    }
    case '-':
    {
        returnValue = new SubtractionOperator(leftOperand, rightOperand);
        break;
    }
    case '*':
    {
        returnValue = new MultiplicationOperator(leftOperand, rightOperand);
        break;
    }
    case '/':
    {
        returnValue = new DivisionOperator(leftOperand, rightOperand);
        break;
    }
    }

    return returnValue;
}

IOperand *ExpressionParser::parse(const std::string &expression)
{
    int index = 0;
    return parse(expression, index);
}

IOperand *ExpressionParser::parse(const std::string &expression, int &index)
{
    ignoreSpaces(expression, index);

    if (std::isdigit(expression[index]))
    {
        ll number = 0;

        while (isdigit(expression[index]))
            number = number * 10 + expression[index++] - '0';

        return new Operand(number);
    }

    index++;
    char operation = expression[index++];

    IOperand *leftOperand = parse(expression, index);
    IOperand *rightOperand = parse(expression, index);
    IOperand *returnValue = nullptr;

    ignoreSpaces(expression, index);
    index++;

    switch (operation)
    {
    case '+':
    {
        returnValue = new AdditionOperator(leftOperand, rightOperand);
        break;
    }
    case '-':
    {
        returnValue = new SubtractionOperator(leftOperand, rightOperand);
        break;
    }
    case '*':
    {
        returnValue = new MultiplicationOperator(leftOperand, rightOperand);
        break;
    }
    case '/':
    {
        returnValue = new DivisionOperator(leftOperand, rightOperand);
        break;
    }
    }

    return returnValue;
}

void ExpressionParser::ignoreSpaces(std::istream &stream)
{
    while (std::isspace(stream.peek()))
        stream.ignore();
}

void ExpressionParser::ignoreSpaces(const std::string &expression, int &index)
{
    while (std::isspace(expression[index]))
        index++;
}

