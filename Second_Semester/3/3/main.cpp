#include <iostream>
#include "sortedlist.h"
#include "sortedset.h"

using std::cin;
using std::cout;

int main()
{
    SortedList *first = new SortedList;
    SortedList *second = new SortedList;
    SortedList *third = new SortedList;
    SortedList *forth = new SortedList;

    int size[3] = {10, 6, 8};

    int firstArray[] = {256, 19824, 385, 397, 456, 137, 486, 864, 152, 954};
    int secondArray[] = {654, 896, 2678, 54, 1538, 1533};
    int thirdArray[] = {153, 1678, 157, 9544, 486, 3576, 156, 415};

    for (int i = 0; i < size[0]; i++)
        first->add(firstArray[i]);

    for (int i = 0; i < size[1]; i++)
    {
        second->add(secondArray[i]);
        forth->add(secondArray[i]);
    }

    for (int i = 0; i < size[2]; i++)
        third->add(thirdArray[i]);

    SortedSet *sortedSet = new SortedSet;

    first->print();
    second->print();
    third->print();

    cout << "First " << (sortedSet->exists(first) ? "exists" : "doesn't exist") << std::endl;
    sortedSet->add(first);
    cout << "First " << (sortedSet->exists(first) ? "exists" : "doesn't exist") << std::endl;
    cout << "Second " << (sortedSet->exists(second) ? "exists" : "doesn't exist") << std::endl;

    sortedSet->add(second);

    cout << "Second " << (sortedSet->exists(second) ? "exists" : "doesn't exist") << std::endl;
    cout << "Forth " << (sortedSet->exists(forth) ? "exists" : "doesn't exist") << std::endl;

    sortedSet->add(second);
    sortedSet->add(third);
    sortedSet->remove(second);

    cout << "Second " << (sortedSet->exists(second) ? "exists" : "doesn't exist") << std::endl;
    cout << "Forth " << (sortedSet->exists(forth) ? "exists" : "doesn't exist") << std::endl;

    sortedSet->add(forth);
    cout << "Second " << (sortedSet->exists(second) ? "exists" : "doesn't exist") << std::endl;
    cout << "Forth " << (sortedSet->exists(forth) ? "exists" : "doesn't exist") << std::endl;

    cout << "Third " << (sortedSet->exists(third) ? "exists" : "doesn't exist") << std::endl;

    delete first;
    delete second;
    delete third;
    delete forth;
    delete sortedSet;
    return 0;
}

