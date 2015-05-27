#include <iostream>
#include "doublelinkedlisttest.h"
#include "sortedlisttest.h"

int main()
{
    DoubleLinkedListTest dlltest;
    QTest::qExec(&dlltest);
    SortedListTest sltest;
    QTest::qExec(&sltest);
    return 0;
}
