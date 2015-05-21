#pragma once
#include "../../../Some_Useful_Things/Exceptions/nullpointer.h"

/// @brief The SharedPointer class is the... shared pointer class
template <typename T>
class SharedPointer
{
public:
    /// @brief SharedPointer - creates nullpointer or the pointer at the object
    SharedPointer(T *obj = nullptr);
    ~SharedPointer();
    ///@brief SharedPointer - creates the copy of ptr
    SharedPointer(const SharedPointer& ptr);

    /**
     * @brief operator = makes ptr share the pointer with this pointer
     * @return reference to that object
     */
    SharedPointer &operator=(const SharedPointer& ptr);
    /// @brief operator -> allows access to the fields of myObj
    T *operator->();
    /// @brief operator * returns the reference to myObj.
    T &operator*();
    /// @brief release releases the pointer
    void release();
    /// @brief getCount returns number of copies
    int getCount();
private:
    T *myObj;
    int *numberOfCopies;
};



template <typename T>
SharedPointer<T>::SharedPointer(T *obj) : myObj(obj), numberOfCopies(nullptr)
{
    if (obj)
        numberOfCopies = new int(1);
}

template <typename T>
SharedPointer<T>::~SharedPointer()
{
    if (numberOfCopies)
    {
        (*numberOfCopies)--;

        if (!*numberOfCopies)
            delete myObj;
    }
}

template <typename T>
SharedPointer<T>::SharedPointer(const SharedPointer<T> &ptr) : myObj(ptr.myObj), numberOfCopies(ptr.numberOfCopies)
{
    if (numberOfCopies)
        (*numberOfCopies)++;
}

template <typename T>
SharedPointer<T> &SharedPointer<T>::operator=(const SharedPointer<T> &ptr)
{
    if (numberOfCopies)
    {
        (*numberOfCopies)--;

        if (!*numberOfCopies)
        {
            delete numberOfCopies;
            delete myObj;
        }
    }

    numberOfCopies = ptr.numberOfCopies;
    myObj = ptr.myObj;

    if (numberOfCopies)
        (*numberOfCopies)++;

    return *this;
}

template <typename T>
T *SharedPointer<T>::operator->()
{
    return myObj;
}

template <typename T>
T &SharedPointer<T>::operator*()
{
    if (!myObj)
        throw NullpointerException();

    return (*myObj);
}

template <typename T>
void SharedPointer<T>::release()
{
    if (numberOfCopies)
    {
        (*numberOfCopies)--;

        if (!*numberOfCopies)
        {
            delete numberOfCopies;
            delete myObj;
        }

        numberOfCopies = nullptr;
        myObj = nullptr;
    }
}

template <typename T>
int SharedPointer<T>::getCount()
{
    return (numberOfCopies ? *numberOfCopies : 0);
}
