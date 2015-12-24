#pragma once

#include <QtTest/QtTest>

#include "computerfactory.h"
#include "computer.h"
#include "operatingsystem.h"
#include "macrodefinition.h"

class ComputerFactoryTest : public QObject
{
    Q_OBJECT
private slots:
    void init()
    {
        factory = new ComputerFactory;
    }

    void cleanup()
    {
        safeDelete(factory);
    }

    void testSimpleAddition()
    {
        QVERIFY(factory->addOperatingSystem("Windows", 75));
    }

    void testInstanceCreation()
    {
        factory->addOperatingSystem("Windows" , 75);
        Computer *instance = factory->createComputerWithOs("Windows");
        bool notNull = instance != nullptr;

        safeDelete(instance);

        QVERIFY(notNull);
    }

    void testDoubleAddition()
    {
        factory->addOperatingSystem("Windows", 75);
        QVERIFY(!factory->addOperatingSystem("Windows", 75));
    }

    void testCreatingNonexistingOs()
    {
        factory->addOperatingSystem("Windows", 75);
        QVERIFY2(factory->addOperatingSystem("Linux", 23), "Second OS adding error!");
        Computer *instance = factory->createComputerWithOs("Dos");
        bool isNull = instance == nullptr;

        safeDelete(instance);

        QVERIFY2(isNull, "Computer with nonexistent OS was created");
    }

    void testInfecting()
    {
        factory->addOperatingSystem("Windows", 100);
        factory->addOperatingSystem("Linux", 0);

        Computer *computerWithWindows = factory->createComputerWithOs("Windows");
        Computer *computerWithLinux = factory->createComputerWithOs("Linux");

        computerWithWindows->addRelative(computerWithLinux);
        computerWithWindows->setInfected(true);
        computerWithWindows->tryToInfectRelatives();

        bool infected = computerWithLinux->isInfected();

        delete computerWithWindows;
        delete computerWithLinux;

        QVERIFY2(!infected, "Computer with 0 chance to be infected was infected");
    }

    void testInfecting2()
    {
        factory->addOperatingSystem("Windows", 100);
        factory->addOperatingSystem("Linux", 0);

        Computer *computerWithWindows = factory->createComputerWithOs("Windows");
        Computer *computerWithLinux = factory->createComputerWithOs("Linux");

        computerWithWindows->addRelative(computerWithLinux);
        computerWithLinux->setInfected(true);
        computerWithLinux->tryToInfectRelatives();

        bool infected = computerWithWindows->isInfected();

        delete computerWithWindows;
        delete computerWithLinux;

        QVERIFY2(infected, "Computer with 100 chance to be infected wasnt infected");
    }

private:
    ComputerFactory *factory;
};
