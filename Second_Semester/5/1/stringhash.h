#pragma once
#include "ihashfunction.h"

/**
 * @brief The StringHash class - polynomial hash function
 */
class StringHash : public IHashFunction
{
public:
    StringHash(const unsigned int mod);
    ~StringHash();
    unsigned int function(const std::string &obj) const;
};

