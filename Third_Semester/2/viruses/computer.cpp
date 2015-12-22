#include "computer.h"
#include "operatingsystem.h"
#include <QDebug>

Computer::Computer(const Computer *anotherComputer)
    : Computer(anotherComputer->OperatingSystem_, anotherComputer->infected_)
{
}

Computer::Computer(const OperatingSystem *OperatingSystem) :
    Computer(OperatingSystem, false)
{
}

Computer::Computer(const OperatingSystem *OperatingSystem, bool infected) :
    OperatingSystem_(OperatingSystem), infected_(infected)
{
}

void Computer::setInfected(bool infected)
{
    infected_ = infected;
}

bool Computer::isInfected() const
{
    return infected_;
}

void Computer::addRelative(Computer *relative)
{
    if (!relatives_.contains(relative))
    {
        relatives_.append(relative);
        relative->addRelative(this);
    }
}

void Computer::tryToInfectRelatives()
{
    if (!infected_)
        return;

    QList<Computer *>::iterator relative = relatives_.begin();
    while (relative != relatives_.end())
    {
        (*relative)->infect();
        relative++;
    }
}

void Computer::infect()
{
    infected_ |= (qrand() % 101 > OperatingSystem_->getResistance());
}


