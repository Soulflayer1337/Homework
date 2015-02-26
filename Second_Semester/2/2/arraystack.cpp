#include "arraystack.h"

ArrayStack::ArrayStack() : capacity(256), size(0), array(new int[256])
{
}

ArrayStack::~ArrayStack()
{
    delete[] array;
}

void ArrayStack::push(int value)
{
    if (size == capacity)
    {
        int *newArray = new int[capacity *= 2];

        for (int i = 0; i < size; i++)
            newArray[i] = array[i];

        delete[] array;
        array = newArray;
    }

    array[size++] = value;
}

int ArrayStack::top()
{
    return (isEmpty() ? 0 : array[size - 1]);
}

int ArrayStack::pop()
{
    if (isEmpty())
        return 0;

    int returnValue = array[--size];

    if (capacity > 256 && (size * 2 == capacity))
    {
        int *newArray = new int[size];

        for (int i = 0; i < size; i++)
            newArray[i] = array[i];

        delete[] array;
        array = newArray;
    }

    return returnValue;
}

bool ArrayStack::isEmpty() const
{
    return size == 0;
}
