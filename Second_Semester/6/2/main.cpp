#include "avltreetest.h"
#include "settest.h"

int main()
{
    AVLTreeTest avlTreeTest;
    QTest::qExec(&avlTreeTest);
    SetTest setTest;
    QTest::qExec(&setTest);
    return 0;
}

