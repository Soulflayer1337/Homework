#pragma once

#include <QObject>

class InputManager;
class Cannon;

class InputObserver : public QObject
{
    Q_OBJECT
public:
    explicit InputObserver(QObject *parent, Cannon *subject);

signals:
    void inputInvoked(const QString &message);

protected slots:
    void buttonReleased();
    void moveRightPressed();
    void moveLeftPressed();
    void angleUpPressed();
    void angleDownPressed();
    void shootPressed();
    void changePressed();

private:
    Cannon *subject_;
};
