#include "fakenumbergenerator.h"

FakeNumberGenerator::FakeNumberGenerator()
{
}

int FakeNumberGenerator::getNumber()
{
    if (numbers.isEmpty())
    {
        return 42;
    }
    else
    {
        return numbers.dequeue();
    }
}

void FakeNumberGenerator::addNumberToQueue(int number)
{
    numbers.enqueue(number);
}

void FakeNumberGenerator::clearQueue()
{
    numbers.clear();
}

