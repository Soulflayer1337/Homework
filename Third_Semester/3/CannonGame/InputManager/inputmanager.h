#pragma once

#include <QObject>

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
