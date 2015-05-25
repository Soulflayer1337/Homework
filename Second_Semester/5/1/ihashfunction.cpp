#include "ihashfunction.h"

IHashFunction::IHashFunction(const unsigned int mod) : module(mod)
{
}

IHashFunction::~IHashFunction()
{
}

unsigned int IHashFunction::getHash(const std::string &obj) const
{
    return function(obj) % module;
}

unsigned int IHashFunction::getModule() const
{
    return module;
}

