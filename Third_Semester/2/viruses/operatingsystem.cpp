#include "operatingsystem.h"

OperatingSystem::OperatingSystem(const QString &osName, int resistance) :
    osName_(osName), resistance_(resistance)
{
}

const QString &OperatingSystem::getOsName() const
{
    return osName_;
}

int OperatingSystem::getResistance() const
{
    return resistance_;
}

