#include "jenkinshash.h"

JenkinsHash::JenkinsHash(const unsigned int mod) : IHashFunction(mod)
{
}

JenkinsHash::~JenkinsHash()
{
}

unsigned int JenkinsHash::function(const std::string &obj) const
{
    unsigned int hash = 0;
    unsigned int length = obj.length();

    for (unsigned int i = 0; i < length; i++)
    {
        hash += obj[i];
        hash += (hash << 10);
        hash ^= (hash >> 6);
    }

    hash += (hash << 3);
    hash ^= (hash >> 11);
    hash += (hash << 15);

    return hash;
}

