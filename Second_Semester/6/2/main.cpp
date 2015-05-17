#include "set.h"
#include "settest.h"

int main()
{
    SetTest setTest;
    QTest::qExec(&setTest);
    std::cout << std::endl;

    Set<int> *firstSet = new Set<int>;
    Set<int> *secondSet = new Set<int>;

    firstSet->add(42);
    firstSet->add(53);
    firstSet->add(14);
    firstSet->add(54);
    firstSet->add(55);
    firstSet->printTree();

    secondSet->add(35);
    secondSet->add(15);
    secondSet->add(14);
    secondSet->add(13);
    secondSet->add(53);
    secondSet->add(78);
    secondSet->add(35);
    secondSet->printTree();

    Set<int> *unionSet = firstSet->setUnion(secondSet);
    Set<int> *intersectionSet = firstSet->setIntersection(secondSet);
    unionSet->printTree();
    intersectionSet->printTree();

    delete firstSet;
    delete secondSet;
    delete unionSet;
    return 0;
}

