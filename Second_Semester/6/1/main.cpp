#include <iostream>
#include <fstream>
#include "expressionparser.h"
#include "expressionparsertest.h"

int main()
{
    ExpressionParserTest expressionParserTest;
    QTest::qExec(&expressionParserTest);

    std::cout << "Enter the file name: ";
    std::string filePath = "";
    std::getline(std::cin, filePath);

    std::ifstream in(filePath);

    if (!in.is_open())
    {
        std::cout << "The file doesn't exist!\n";
        return 0;
    }

    IOperand *expression = ExpressionParser::parse(in);
    in.close();

    expression->print();

    try
    {
        std::cout << "\n" << expression->count() << std::endl;
    }
    catch (DividedByZeroException)
    {
        std::cout << "Oops, divided by zero!\n";
    }

    delete expression;
    return 0;
}

