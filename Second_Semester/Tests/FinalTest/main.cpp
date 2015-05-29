#include <iostream>
#include "bintreetest.h"

using namespace std;

int main()
{
    BinTreeTest binTreeTest;
    QTest::qExec(&binTreeTest);
    return 0;
}

