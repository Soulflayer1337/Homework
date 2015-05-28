#include <iostream>
#include "sortedlisttest.h"
#include "sortedsettest.h"

int main()
{
    SortedListTest sortedListTest;
    QTest::qExec(&sortedListTest);
    std::cout << std::endl;
    SortedSetTest sortedSetTest;
    QTest::qExec(&sortedSetTest);
    return 0;
}

