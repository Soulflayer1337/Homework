#pragma once

#include "inputmanager.h"

class Network;
class Cannon;

class NetworkInputManager : public InputManager
{
public:
    explicit NetworkInputManager(Network *parent, Cannon *subject);

    void networkInputInvoked(const QString &message);

private:
    Cannon *subject_;
};
