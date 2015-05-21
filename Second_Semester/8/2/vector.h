#pragma once

class OutOfRangeException
{
};

/// \brief The Vector class - the string of integers
template <unsigned int dimmension>
class Vector
{
public:
    Vector();
    Vector(const Vector &vector);
    ~Vector();

    /// \brief isZeroVector - checks if current vector is zero vector.
    bool isZeroVector() const;

    /// \brief operator = - overlaing of assignment operation
    const Vector<dimmension> &operator=(const Vector<dimmension> &that);

    /// \brief operator + - overloading of sum operation
    const Vector<dimmension> operator+(const Vector<dimmension> &that) const;
    /// \brief operator - overloading of subtraction operation
    const Vector<dimmension> operator-(const Vector<dimmension> &that) const;
    /// \brief operator * - dor product
    int operator*(const Vector<dimmension> &that) const;

    /// \brief operator == - checks if contents of vector is equal
    bool operator==(const Vector<dimmension> &that) const;
    /// \brief operator != - checks if contents of vector is unequal
    bool operator!=(const Vector<dimmension> &that) const;

    /// \brief operator [] - overloading indexation
    int &operator[](unsigned int index) const;
private:
    int *coefficients;
};

template <unsigned int dimmension>
Vector<dimmension>::Vector()
{
    coefficients = new int[dimmension];

    for (unsigned int i = 0; i < dimmension; i++)
        coefficients[i] = 0;
}

template <unsigned int dimmension>
Vector<dimmension>::Vector(const Vector<dimmension> &vector)
{
    coefficients = new int[dimmension];

    for (unsigned int i = 0; i < dimmension; i++)
        coefficients[i] = vector[i];
}

template <unsigned int dimmension>
Vector<dimmension>::~Vector()
{
    delete[] coefficients;
}

template <unsigned int dimmension>
bool Vector<dimmension>::isZeroVector() const
{
    unsigned int index = 0;

    while (index < dimmension && !coefficients[index])
        index++;

    return (index == dimmension);
}

template <unsigned int dimmension>
const Vector<dimmension> &Vector<dimmension>::operator=(const Vector<dimmension> &that)
{
    for (unsigned int i = 0; i < dimmension; i++)
        coefficients[i] = that[i];
    return *this;
}

template <unsigned int dimmension>
int &Vector<dimmension>::operator[](unsigned int index) const
{
    if (index < dimmension)
        return coefficients[index];
    else
        throw OutOfRangeException();
}

template <unsigned int dimmension>
const Vector<dimmension> Vector<dimmension>::operator+(const Vector<dimmension> &that) const
{
    Vector<dimmension> newVector(*this);

    for (unsigned int i = 0; i < dimmension; i++)
        newVector[i] += that[i];

    return newVector;
}

template <unsigned int dimmension>
const Vector<dimmension> Vector<dimmension>::operator-(const Vector<dimmension> &that) const
{
    Vector<dimmension> newVector(*this);

    for (unsigned int i = 0; i < dimmension; i++)
        newVector[i] -= that[i];

    return newVector;
}

template <unsigned int dimmension>
int Vector<dimmension>::operator*(const Vector<dimmension> &that) const
{
    int res = 0;

    for (unsigned int i = 0; i < dimmension; i++)
        res += coefficients[i] * that[i];

    return res;
}

template <unsigned int dimmension>
bool Vector<dimmension>::operator==(const Vector<dimmension> &that) const
{
    unsigned int index = 0;

    while (index < dimmension && coefficients[index] == that[index])
        index++;

    return (index == dimmension);
}

template <unsigned int dimmension>
bool Vector<dimmension>::operator!=(const Vector<dimmension> &rightVector) const
{
    return !(*this == rightVector);
}
