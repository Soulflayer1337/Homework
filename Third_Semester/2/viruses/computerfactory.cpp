#include "computerfactory.h"

#include "operatingsystem.h"
#include "computer.h"
#include "macrodefinition.h"

ComputerFactory::ComputerFactory()
{
}

ComputerFactory::~ComputerFactory()
{
    QMap<QString, OperatingSystem *>::iterator iterator = OperatingSystems_.begin();

    while (iterator != OperatingSystems_.end())
    {
        safeDelete(iterator.value());
        iterator++;
    }
}

bool ComputerFactory::addOperatingSystem(const QString &name, int infectionChance)
{
    bool isVacantName = !OperatingSystems_.contains(name);

    if (isVacantName)
    {
        OperatingSystems_.insert(name, new OperatingSystem(name, 100 - infectionChance));
    }

    return isVacantName;
}

Computer *ComputerFactory::createComputerWithOs(const QString &osName) const
{
    Computer *newComputer = nullptr;
    QMap<QString, OperatingSystem *>::const_iterator iterator = OperatingSystems_.find(osName);

    if (iterator != OperatingSystems_.end())
    {
        newComputer = new Computer(iterator.value());
    }

    return newComputer;
}

