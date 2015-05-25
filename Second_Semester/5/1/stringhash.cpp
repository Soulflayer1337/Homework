#include "stringhash.h"

StringHash::StringHash(const unsigned int mod) : IHashFunction(mod)
{
}

StringHash::~StringHash()
{
}

unsigned int StringHash::function(const std::string &obj) const
{
    const int multipler = 53;
    size_t hash = 0;
    size_t multPow = 1;

    size_t length = obj.length();

    for (size_t i = 0; i < length; i++)
    {
        hash = (hash + (obj[i] - 'a' + 1) * multPow) % module;
        multPow = (multPow * multipler) % module;
    }

    return hash;
}

