#pragma once

#include "inputmanager.h"

class Network;
class Cannon;

/**
 * \brief The NetworkInputManager class handles the commands from the network.
 */
class NetworkInputManager : public InputManager
{
    Q_OBJECT
public:
    explicit NetworkInputManager(Network *parent, Cannon *subject);

    /// \brief translates messages and invokes the commands.
    void networkInputInvoked(const QString &message);

private:
    Cannon *subject_;
};
