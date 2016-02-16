#include "inputobserver.h"

#include "InputManager/inputmanager.h"
#include "GameObjects/cannon.h"

InputObserver::InputObserver(QObject *parent, Cannon *subject) :
    QObject(parent),
    subject_(subject)
{
    InputManager *inputManager = subject->getInputManager();

    connect(inputManager, SIGNAL(angleDownPressed()), this, SLOT(angleDownPressed()));
    connect(inputManager, SIGNAL(angleUpPressed()),   this, SLOT(angleUpPressed()));
    connect(inputManager, SIGNAL(moveRightPressed()), this, SLOT(moveRightPressed()));
    connect(inputManager, SIGNAL(moveLeftPressed()),  this, SLOT(moveLeftPressed()));
    connect(inputManager, SIGNAL(changePressed()),    this, SLOT(changePressed()));
    connect(inputManager, SIGNAL(shootPressed()),     this, SLOT(shootPressed()));
    connect(inputManager, SIGNAL(buttonReleased()),   this, SLOT(buttonReleased()));
}

void InputObserver::buttonReleased()
{
    float xPosition = 0;
    float yPosition = 0;
    subject_->getPosition(xPosition, yPosition);
    emit inputInvoked(QString("K ") + QString::number(int(xPosition)) +
                      " " + QString::number(subject_->getAngleOfCannonDegrees()) +
                      " " + QString::number(subject_->isFacingRight()));
}

void InputObserver::moveRightPressed()
{
    emit inputInvoked(QString("KR"));
}

void InputObserver::moveLeftPressed()
{
    emit inputInvoked(QString("KL"));
}

void InputObserver::angleUpPressed()
{
    emit inputInvoked(QString("KU"));
}

void InputObserver::angleDownPressed()
{
    emit inputInvoked(QString("KD"));
}

void InputObserver::shootPressed()
{
    emit inputInvoked(QString("KS"));
}

void InputObserver::changePressed()
{
    emit inputInvoked(QString("KC"));
}
