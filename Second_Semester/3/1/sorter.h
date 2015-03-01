#pragma once

class Sorter
{
protected:
    void swap(int &first, int &second);
public:
    virtual void sort(int *array, int size) = 0;
};
