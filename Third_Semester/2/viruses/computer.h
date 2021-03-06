#pragma once

#include <QList>

class OperatingSystem;
class INumberGenerator;

/// @brief The Computer class - contains information about a concrete computer and allows to interact with other computers
class Computer
{
public:
    Computer(const Computer *anotherComputer);
    Computer(const OperatingSystem *OperatingSystem);
    Computer(const OperatingSystem *OperatingSystem, bool infected);
    ~Computer();

    /// @brief setInfected - surprisingly, it allows to set the infected flag
    void setInfected(bool infected = true);
    /// @brief isInfected returns infected_
    bool isInfected() const;

    /// @brief setNumberGenerator sets new number generator.
    /// Does nothing if newNumberGenerator is nullptr.
    /// \return pointer to old number generator or nullptr if newNumberGenerator is nullptr
    INumberGenerator *setNumberGenerator(INumberGenerator *newNumberGenerator);
    /// @brief addRelative - sets a connection between this and relative. Does nothing if such connection already exists.
    void addRelative(Computer *relative);
    /// @brief tryToInfectRelatives - tryes to infect its relatives if the computer is infected. Does nothing otherwise.
    void tryToInfectRelatives();
private:
    /// @brief infect - tryes to become infected if it's not.
    void infect();

    QList<Computer *> relatives_;
    const OperatingSystem *OperatingSystem_;
    bool infected_;
    INumberGenerator *numberGenerator_;
};
