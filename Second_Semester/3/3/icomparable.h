#pragma once

/**
 * @brief The IComparable class - interface of comparator
 *
 */
class IComparable
{
public:
    virtual ~IComparable(){}
    /**
     * @brief compareTo - compares two instance of the class.
     * @return 1 (this > obj), 0 (equivalence), 1 (this < obj)
     */
    virtual int compareTo(const IComparable *obj) const = 0;
    /**
     * @brief isEqual - compares two instance of the class
     * @return 1 (this == obj), 0 (otherwise)
     */
    virtual bool isEqual(const IComparable *obj) const = 0;
    /**
     * @brief copy - creates a copy of the class
     */
    virtual IComparable *copy() const = 0;
};
