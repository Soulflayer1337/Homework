#include "computer.h"

#include <QDebug>

#include "operatingsystem.h"
#include "randomnumbergenerator.h"
#include "macrodefinition.h"

Computer::Computer(const Computer *anotherComputer)
    : Computer(anotherComputer->OperatingSystem_, anotherComputer->infected_)
{
}

Computer::Computer(const OperatingSystem *OperatingSystem) :
    Computer(OperatingSystem, false)
{
}

Computer::Computer(const OperatingSystem *OperatingSystem, bool infected) :
    OperatingSystem_(OperatingSystem),
    infected_(infected),
    numberGenerator_(new RandomNumberGenerator)
{
}

Computer::~Computer()
{
    safeDelete(numberGenerator_);
}

void Computer::setInfected(bool infected)
{
    infected_ = infected;
}

bool Computer::isInfected() const
{
    return infected_;
}

INumberGenerator *Computer::setNumberGenerator(INumberGenerator *newNumberGenerator)
{
    INumberGenerator *toReturn = nullptr;

    if (newNumberGenerator)
    {
        toReturn = numberGenerator_;
        numberGenerator_ = newNumberGenerator;
    }

    return toReturn;
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
    infected_ |= (numberGenerator_->getNumber() % 101 > OperatingSystem_->getResistance());
}


