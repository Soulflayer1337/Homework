#pragma once

#include <QtTest/QtTest>

#include "computer.h"
#include "computerfactory.h"
#include "network.h"
#include "macrodefinition.h"
#include "fakenumbergenerator.h"

class NetworkTest : public QObject
{
    Q_OBJECT
private slots:
    void initTestCase()
    {
        factory = new ComputerFactory;

        factory->addOperatingSystem("Windows", 30);
        factory->addOperatingSystem("Linux", 15);
        factory->addOperatingSystem("Mac", 5);
        factory->addOperatingSystem("CoinOs", 50);
        factory->addOperatingSystem("ProtectedOs", 0);
        factory->addOperatingSystem("NakedOs", 100);
    }

    void cleanupTestCase()
    {
        safeDelete(factory);
    }

    void init()
    {
        network = new Network;
    }

    void cleanup()
    {
        safeDelete(network);
    }

    void creationWithoutMatrixTest()
    {
        QList<Computer *> computers;
        Computer *centralComputer = factory->createComputerWithOs("Windows");
        centralComputer->setInfected(true);

        for (int i = 0; i < 5; i++)
        {
            Computer *relativeComputer = factory->createComputerWithOs("NakedOs");
            relativeComputer->addRelative(centralComputer);
            computers.append(relativeComputer);
        }

        computers.append(centralComputer);
        network->createFromListAndMatrix(computers);

        QVERIFY(computers.size() == 0);
        QVERIFY2(network->getComputers().at(0)->isInfected(), "Central computer isn't the first");
    }

    void resetTest()
    {
        QList<Computer *> computers;
        Computer *centralComputer = factory->createComputerWithOs("Windows");
        centralComputer->setInfected(true);

        for (int i = 0; i < 5; i++)
        {
            Computer *relativeComputer = factory->createComputerWithOs("NakedOs");
            relativeComputer->addRelative(centralComputer);
            computers.append(relativeComputer);
        }

        computers.append(centralComputer);
        network->createFromListAndMatrix(computers);
        computers = network->reset();

        QVERIFY2(computers.size() == 6, "Number of computers isn't 6");
        QVERIFY(computers[0] == centralComputer);

        for (int i = 0; i < computers.size(); i++)
        {
            safeDelete(computers[i]);
        }
    }

    void creationByUsingMatrixTest()
    {
        QList<Computer *> computers;
        Computer *centralComputer = factory->createComputerWithOs("Windows");
        centralComputer->setInfected(true);

        bool **matrix = new bool*[6];

        for (int i = 0; i < 6; i++)
        {
            matrix[i] = new bool[6];
            for (int j = 0; j < 6; j++)
            {
                matrix[i][j] = false;
            }
        }

        for (int i = 0; i < 5; i++)
        {
            matrix[i][5] = matrix[5][i] = true;
            Computer *relativeComputer = factory->createComputerWithOs("NakedOs");
            computers.append(relativeComputer);
        }

        computers.append(centralComputer);
        network->createFromListAndMatrix(computers, matrix, true);
        computers = network->reset();

        QVERIFY2(computers.at(0)->isInfected(), "Central computer isn't the first");

        for (int i = 0; i < computers.size(); i++)
        {
            safeDelete(computers[i]);
        }
    }

    void addComputerTest()
    {
        Computer *centralComputer = factory->createComputerWithOs("Windows");
        centralComputer->setInfected(true);
        network->addComputer(centralComputer);

        for (int i = 0; i < 5; i++)
        {
            Computer *relativeComputer = factory->createComputerWithOs("NakedOs");
            relativeComputer->addRelative(centralComputer);
            network->addComputer(relativeComputer);
        }

        QVERIFY(network->getComputers().size() == 6);
        QVERIFY2(network->getComputers().at(0)->isInfected(), "Central computer isn't infected");

        for (int i = 1; i < 6; i++)
        {
            QVERIFY2(!network->getComputers().at(i)->isInfected(), "Relative computer is infected");
        }
    }

    void simulationTest()
    {
        QList<Computer *> computers;
        Computer *centralComputer = factory->createComputerWithOs("Windows");
        centralComputer->setInfected(true);

        for (int i = 0; i < 5; i++)
        {
            Computer *relativeComputer = factory->createComputerWithOs("NakedOs");
            relativeComputer->addRelative(centralComputer);
            computers.append(relativeComputer);
        }

        computers.append(centralComputer);
        network->createFromListAndMatrix(computers);

        network->simulation();

        for (int i = 0; i < 6; i++)
        {
            QVERIFY(network->getComputers().at(i)->isInfected());
        }
    }

    void simulationTest2()
    {
        // The scheme:
        // o---X---o---I---o---o   o
        // o - 100% chance of infection
        // X - 0% chance of infection
        // I - infected
        // --- - path between computers
        QList<Computer *> computers;

        for (int i = 0; i < 7; i++)
        {
            Computer *currentComputer = nullptr;
            if (i == 1)
            {
                currentComputer = factory->createComputerWithOs("ProtectedOs");
            }
            else if (i == 3)
            {
                currentComputer = factory->createComputerWithOs("Windows");
                currentComputer->setInfected(true);
            }
            else
            {
                currentComputer = factory->createComputerWithOs("NakedOs");
            }
            computers.append(currentComputer);
        }

        QList<Computer *> computerObserver(computers);

        bool **matrix = new bool*[7];
        for (int i = 0; i < 7; i++)
        {
            matrix[i] = new bool[7];
            for (int j = 0; j < 7; j++)
            {
                matrix[i][j] = false;
            }
        }

        for (int i = 1; i < 6; i++)
        {
            matrix[i - 1][i] = matrix[i][i - 1] = true;
        }

        network->createFromListAndMatrix(computers, matrix, true);
        network->simulation();
        // The scheme:
        // o---X---I---I---I---o   o
        for (int i = 0; i < 7; i++)
        {
            if (i < 5 && i > 1)
            {
                QVERIFY(computerObserver.at(i)->isInfected());
            }
            else
            {
                QVERIFY(!computerObserver.at(i)->isInfected());
            }
        }

        network->simulation();
        // The scheme:
        // o---X---I---I---I---I   o
        for (int i = 0; i < 7; i++)
        {
            if (i < 6 && i > 1)
            {
                QVERIFY(computerObserver.at(i)->isInfected());
            }
            else
            {
                QVERIFY(!computerObserver.at(i)->isInfected());
            }
        }

        network->simulation();
        // Nothing changed
        for (int i = 0; i < 7; i++)
        {
            if (i < 6 && i > 1)
            {
                QVERIFY(computerObserver.at(i)->isInfected());
            }
            else
            {
                QVERIFY(!computerObserver.at(i)->isInfected());
            }
        }
    }

    void simulationTest3()
    {
        Computer *infectedComputer = factory->createComputerWithOs("CoinOs");
        infectedComputer->setInfected();

        Computer *firstComputer = factory->createComputerWithOs("CoinOs");
        FakeNumberGenerator *firstGenerator = new FakeNumberGenerator;
        delete firstComputer->setNumberGenerator(firstGenerator);
        firstGenerator->addNumberToQueue(15);
        firstGenerator->addNumberToQueue(65);

        Computer *secondComputer = factory->createComputerWithOs("CoinOs");
        FakeNumberGenerator *secondGenerator = new FakeNumberGenerator;
        delete secondComputer->setNumberGenerator(secondGenerator);
        secondGenerator->addNumberToQueue(45);
        secondGenerator->addNumberToQueue(13);
        secondGenerator->addNumberToQueue(25);
        secondGenerator->addNumberToQueue(97);

        infectedComputer->addRelative(firstComputer);
        infectedComputer->addRelative(secondComputer);
        firstComputer->addRelative(secondComputer);

        network->addComputer(firstComputer);
        network->addComputer(secondComputer);
        network->addComputer(infectedComputer);
        network->simulation();

        QVERIFY(!firstComputer->isInfected());
        QVERIFY(!secondComputer->isInfected());
        network->simulation();

        QVERIFY(firstComputer->isInfected());
        QVERIFY(!secondComputer->isInfected());
        network->simulation();

        QVERIFY(firstComputer->isInfected());
        QVERIFY(secondComputer->isInfected());
    }

private:
    Network *network;
    ComputerFactory *factory;
};
