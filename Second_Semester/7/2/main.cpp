#include <iostream>
#include "listtest.h"
#include "uniquelisttest.h"

using namespace std;

int main()
{
    ListTest listTest;
    QTest::qExec(&listTest);
    UniqueListTest uniqueListTest;
    QTest::qExec(&uniqueListTest);
    return 0;
}

