#pragma once

#include <QObject>
#include <InputManager/inputmanager.h>

class GameClass;

class Cannon : public QObject
{
    Q_OBJECT
public:
    explicit Cannon(GameClass *parent);
    ~Cannon();

    void update();

    void setInputManager(InputManager *manager);
    InputManager *getInputManager() const;
    void setFacingRight(bool facingRight = true);
    bool isFacingRight() const;
    void setPosition(int xPosition);
    void getPosition(float &xPosition, float &yPosition) const;

    int getAngleOfCannon() const;

signals:
    void updated();

private slots:
    void moveRight();
    void moveLeft();
    void angleUp();
    void angleDown();
    void changeProjectilesType();
    void shoot();
    void stopAction();

private:
    GameClass *gameClass_;
    InputManager *inputManager_;

    int deltaX_;
    int deltaAngle_;
    bool isLightProjectile_;

    bool facingRight_;
    int xPosition_;
    int yPosition_;

    int angleOfCannon_;
};
