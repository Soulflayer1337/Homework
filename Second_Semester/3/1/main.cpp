#include <iostream>
#include "sortertest.h"

int main()
{
    SorterTest sorterTest;
    QTest::qExec(&sorterTest);
    return 0;
}

