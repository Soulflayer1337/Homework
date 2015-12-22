#pragma once

#include <QList>

class OperatingSystem;
class Computer;

/// @brief The ComputerFactory class allows us to create new instances of Computer with existing OS.
/// Note that all the instances of Computer should be deleted before the instance of the ComputerFactory they were created by.
class ComputerFactory
{
public:
    ComputerFactory();
    ~ComputerFactory();

    /// @brief addOperatingSystem creates new OperatingSystem. infectionChance should be between 0 and 100. Returns false if OS with such name already exists
    bool addOperatingSystem(const QString &name, int infectionChance);
    /// @brief createComputerWithOs creates new instance of Computer with osName-OS. Returns nullptr if OS with such name already exists
    Computer *createComputerWithOs(const QString &osName) const;
private:
    QList<OperatingSystem *> OperatingSystems_;
};
