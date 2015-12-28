#pragma once

#include <QObject>

class Cannon;
class GameClass;

class Projectile : public QObject
{
    Q_OBJECT
public:
    explicit Projectile(Cannon *parent, float baseAcceleration = 0.0f);

    virtual void update() = 0;
    virtual void explode() = 0;

    int getRadius() const;
    void getPosition(int &xPosition, int &yPosition) const;
    void getAcceleration(float &xAcceleration, float &yAcceleration) const;

signals:
    void updated();

protected:
    GameClass *gameClass_;

    int radius_;

    float xPosition_;
    float yPosition_;

    float xAcceleration_;
    float yAcceleration_;
};
