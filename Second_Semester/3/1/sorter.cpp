#include "sorter.h"

void Sorter::swap(int &first, int &second)
{
    first ^= second;
    second ^= first;
    first ^= second;
}
