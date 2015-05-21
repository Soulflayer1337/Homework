#include <iostream>
#include "bagtest.h"

using namespace std;

int main()
{
    BagTest bagTest;
    QTest::qExec(&bagTest);
    return 0;
}

