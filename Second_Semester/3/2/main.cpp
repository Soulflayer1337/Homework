#include <iostream>
#include "matrixtest.h"
#include "outputertest.h"

int main()
{
    MatrixTest matrixTest;
    QTest::qExec(&matrixTest);
    OutputerTest outputerTest;
    QTest::qExec(&outputerTest);
    return 0;
}

