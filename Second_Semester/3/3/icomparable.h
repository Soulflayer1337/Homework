#pragma once

class IComparable
{
public:
    virtual ~IComparable(){}
    virtual int compareTo(const IComparable *obj) const = 0;
    virtual bool isEqual(const IComparable *obj) const = 0;
    virtual IComparable *copy() const = 0;
};
