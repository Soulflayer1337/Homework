#include <iostream>
#include "vectortest.h"

int main()
{
    VectorTest vectorTest;
    QTest::qExec(&vectorTest);
    return 0;
}

