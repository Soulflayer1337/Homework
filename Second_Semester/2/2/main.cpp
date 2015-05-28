#include <iostream>
#include "calculatortest.h"
#include "linkedstacktest.h"
#include "arraystacktest.h"

using std::cin;
using std::cout;

int main()
{
    ArrayStackTest arrayStackTest;
    QTest::qExec(&arrayStackTest);
    LinkedStackTest linkedStackTest;
    QTest::qExec(&linkedStackTest);
    CalculatorTest calculatorTest;
    QTest::qExec(&calculatorTest);
    return 0;
}
