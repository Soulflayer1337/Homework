#pragma once

#include <QObject>

/**
 * \brief The InputManager class is used by the Cannon class to get input.
 */
class InputManager : public QObject
{
    Q_OBJECT
public:
    explicit InputManager(QObject *parent = nullptr);

signals:
    void buttonReleased();
    void moveRightPressed();
    void moveLeftPressed();
    void angleUpPressed();
    void angleDownPressed();
    void shootPressed();
    void changePressed();

protected:
    Qt::Key pressed_;
};
