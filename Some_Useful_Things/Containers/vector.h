#pragma once
#include "../Exceptions/outofrange.h"

/// \brief The Vector class - the vector class
template <typename T>
class Vector
{
public:
    /**
     * @brief Vector - creates object of the Vector class
     * @param _size - number of elements in the vector
     * @param sample - the sample of the elements contained in vector
     */
    Vector();
    Vector(unsigned int _size);
    Vector(unsigned int _size, const T &sample);
    /**
     * @brief Vector - the copy constructor
     * @param sample - the sample for copying
     */
    Vector(const Vector &sample);
    ~Vector();

    /// \brief operator = - overloading of assignment operation
    Vector &operator=(const Vector &sample);
    /// \brief operator [] - overloading indexation
    T &operator[](unsigned int index);
    /// \brief getLength - returns the number of elements
    unsigned int getLength();
private:
    unsigned int size;
    T *objects;
};

template <typename T>
Vector<T>::Vector() : size(0), objects(nullptr)
{
}

template <typename T>
Vector<T>::Vector(unsigned int _size) : size(_size), objects(nullptr)
{
    if (size)
        objects = new T[size];
}

template <typename T>
Vector<T>::Vector(unsigned int _size, const T &sample) : size(_size)
{
    if (size)
        objects = new T[size];

    for (unsigned int i = 0; i < size; i++)
        objects[i] = sample;
}

template <typename T>
Vector<T>::Vector(const Vector<T> &sample) : Vector(sample.size)
{
    for (unsigned int i = 0; i < size; i++)
        objects[i] = sample[i];
}

template <typename T>
Vector<T>::~Vector()
{
    if (size)
        delete[] objects;
}

template <typename T>
Vector<T> &Vector<T>::operator=(const Vector &sample)
{
    if (size)
        delete[] objects;

    size = sample.size;

    if (size)
    {
        objects = new T[size];

        for (unsigned int i = 0; i < size; i++)
            objects[i] = sample.objects[i];
    }

    return *this;
}

template <typename T>
T &Vector<T>::operator[](unsigned int index)
{
    if (index >= size)
        throw OutOfRangeException();

    return objects[index];
}

template <typename T>
unsigned int Vector<T>::getLength()
{
    return size;
}
