#pragma once

#include <QString>

/// @brief The OperatingSystem class - the class that contains information about OS
class OperatingSystem
{
public:
    OperatingSystem(const QString &osName, int resistance);

    /// @brief getOsName - gets the name of the OS
    const QString &getOsName() const;
    /// @brief getRisistance - returns the resistance of the OS
    int getResistance() const;
private:
    QString osName_;
    int resistance_;
};
