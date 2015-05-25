#pragma once
#include "ihashfunction.h"

/**
 * @brief The JenkinsHash class - Jenkins hash function
 */
class JenkinsHash : public IHashFunction
{
public:
    JenkinsHash(const unsigned int mod);
    ~JenkinsHash();
    unsigned int function(const std::string &obj) const;
};
