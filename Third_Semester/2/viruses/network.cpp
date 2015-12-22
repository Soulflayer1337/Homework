#include "network.h"

#include "computer.h"
#include "macrodefinition.h"

Network::Network() :
    numberOfInfected_(0)
{
}

Network::~Network()
{
    foreach (Computer *computer, computers_)
    {
        safeDelete(computer);
    }
}

QList<Computer *> Network::reset()
{
    QList<Computer *> listToReturn;
    listToReturn.swap(computers_);
    numberOfInfected_  = 0;
    return listToReturn;
}

void Network::createFromListAndMatrix(QList<Computer *> &listOfComputers, bool **&matrix, bool toDelete)
{
    computers_.swap(listOfComputers);
    numberOfInfected_ = 0;

    if (matrix)
    {
        for (int i = 0; i < computers_.size(); i++)
        {
            for (int j = 0; j < computers_.size(); j++)
            {
                if (matrix[i][j])
                {
                    computers_[i]->addRelative(computers_[j]);
                }
            }
        }

        if (toDelete)
        {
            for (int i = 0; i < computers_.size(); i++)
            {
                delete[] matrix[i];
            }
            delete[] matrix;
            matrix = nullptr;
        }
    }

    for (int i = 0; i < computers_.size(); i++)
    {
        if (computers_[i]->isInfected())
        {
            computers_.swap(numberOfInfected_, i);
            numberOfInfected_++;
        }
    }
}

void Network::createFromListAndMatrix(QList<Computer *> &listOfComputers)
{
    bool **matrix = nullptr;
    createFromListAndMatrix(listOfComputers, matrix);
}

void Network::addComputer(Computer *computer)
{
    computers_.append(computer);

    if (computer->isInfected())
    {
        computers_.swap(numberOfInfected_, computers_.size() - 1);
        numberOfInfected_++;
    }
}

void Network::simulation()
{
    for (int i = 0; i < numberOfInfected_; i++)
    {
        computers_[i]->tryToInfectRelatives();
    }

    for (int i = numberOfInfected_; i < computers_.size(); i++)
    {
        if (computers_[i]->isInfected())
        {
            computers_.swap(numberOfInfected_, i);
            numberOfInfected_++;
        }
    }
}

const QList<Computer *> &Network::getComputers()
{
    return computers_;
}
