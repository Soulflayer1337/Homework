#include "networkinputmanager.h"

#include "network/network.h"
#include "GameObjects/cannon.h"

NetworkInputManager::NetworkInputManager(Network *parent, Cannon *subject) :
    InputManager(parent),
    subject_(subject)
{
    subject_->setInputManager(this);
}

void NetworkInputManager::networkInputInvoked(const QString &message)
{
    if (message.at(1) == QChar('R'))
    {
        emit moveRightPressed();
    }
    else if (message.at(1) == QChar('L'))
    {
        emit moveLeftPressed();
    }
    else if (message.at(1) == QChar('U'))
    {
        emit angleUpPressed();
    }
    else if (message.at(1) == QChar('D'))
    {
        emit angleDownPressed();
    }
    else if (message.at(1) == QChar('S'))
    {
        emit shootPressed();
    }
    else if (message.at(1) == QChar('C'))
    {
        emit changePressed();
    }
    else if (message.at(1) == QChar(' '))
    {
        emit buttonReleased();
        QStringList stringList = message.split(" ");
        subject_->setPosition(stringList.at(1).toInt());
        subject_->setAngleOfCannon(stringList.at(2).toInt());
        subject_->setFacingRight(stringList.at(3).toInt());
    }
}

