#pragma once

#include <QList>

class Computer;

/// \brief The Network class provides the way to simulate the work of Network.
/// Network DOESN'T delete the instances of Computer from the list. To get the list you should call reset.
class Network
{
public:
    Network();
    /// \brief Destructor deletes Computer instances in the list of computers from the memory
    ~Network();

    /// \brief reset resets the Network.
    /// \return returns the current list of computers.
    QList<Computer *> reset();

    /// \brief createFromListAndMatrix creates nerwork by using listOfComputers(size() = N) and square matrix(size N*N).
    /// \param listOfComputers - listOfComputers with or without relatives. Infecting should be done before passing the list.
    /// Will be swaped with the current list of computers, so u can use the old list
    /// \param matrix - the adjacency matrix. If nullptr, list will be used as it is.
    /// \param toDelete - should the function delete matrix from memory.
    void createFromListAndMatrix(QList<Computer *> &listOfComputers, bool **&matrix, bool toDelete = false);
    void createFromListAndMatrix(QList<Computer *> &listOfComputers);
    /// \brief addComputer - adds computer to the List of Computer
    void addComputer(Computer *computer);
    /// \brief simulation - one step of simulation
    void simulation();
    /// \brief getComputers - gets the constant list of computers. Useful for tests.
    const QList<Computer *> &getComputers();
private:
    QList<Computer *> computers_;
    int numberOfInfected_;
};
