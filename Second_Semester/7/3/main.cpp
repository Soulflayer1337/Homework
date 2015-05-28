#include <iostream>
#include "sharedpointertest.h"

int main()
{
    SharedPointerTest sharedPointerTest;
    QTest::qExec(&sharedPointerTest);
    return 0;
}
