#include "computerfactory.h"

#include "operatingsystem.h"
#include "computer.h"

ComputerFactory::ComputerFactory()
{
}

ComputerFactory::~ComputerFactory()
{
    while (!OperatingSystems_.isEmpty())
    {
        delete OperatingSystems_.takeFirst();
    }
}

bool ComputerFactory::addOperatingSystem(const QString &name, int infectionChance)
{
    bool isVacantName = true;

    foreach (OperatingSystem *currentOs, OperatingSystems_)
    {
        isVacantName = isVacantName && currentOs->getOsName().compare(name);
    }

    if (isVacantName)
    {
        OperatingSystems_.append(new OperatingSystem(name, 100 - infectionChance));
    }
    return isVacantName;
}

Computer *ComputerFactory::createComputerWithOs(const QString &osName) const
{
    Computer *newComputer = nullptr;

    foreach (OperatingSystem *currentOs, OperatingSystems_)
    {
        if (!currentOs->getOsName().compare(osName))
            newComputer = new Computer(currentOs);
    }

    return newComputer;
}

