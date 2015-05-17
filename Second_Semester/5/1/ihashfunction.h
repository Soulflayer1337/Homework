#pragma once
#include <iostream>

/**
 * @brief The IHashFunction class - an abstract class for HashTable class.
 */
class IHashFunction
{
public:
    /**
     * @brief IHashFunction - initializes the module.
     */
    IHashFunction(const unsigned int mod);
    virtual ~IHashFunction();

    /**
     * @brief getHash - counts hash modulo. Used in HashTable class to prevent some errors.
     */
    unsigned int getHash(const std::string &obj) const;
    unsigned int getModule() const;
    /**
     * @brief function - counts hash
     */
    virtual unsigned int function(const std::string &obj) const = 0;
protected:
    /**
     * @brief module - The module, as well as the size of the hash table.
     */
    const unsigned int module;
};
