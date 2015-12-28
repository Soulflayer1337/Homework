#include "projectile.h"

#include <QtMath>

#include "gameclass.h"
#include "GameObjects/cannon.h"

Projectile::Projectile(Cannon *parent, float baseAcceleration) :
    QObject(parent),
    gameClass_(static_cast<GameClass *>(parent->parent())),
    radius_(1),
    xPosition_(0.0f),
    yPosition_(0.0f),
    xAcceleration_(qCos(parent->getAngleOfCannon())),
    yAcceleration_(qSin(parent->getAngleOfCannon()))
{
    parent->getPosition(xPosition_, yPosition_);
    xPosition_ += xAcceleration_ * 15;
    yPosition_ += 10 + yAcceleration_ * 15;
    xAcceleration_ *= baseAcceleration;
    yAcceleration_ *= baseAcceleration;

    gameClass_->setProjectile(this);
}

int Projectile::getRadius() const
{
    return radius_;
}

void Projectile::getPosition(int &xPosition, int &yPosition) const
{
    xPosition = xPosition_;
    yPosition = yPosition_;
}

void Projectile::getAcceleration(float &xAcceleration, float &yAcceleration) const
{
    xAcceleration = xAcceleration_;
    yAcceleration = yAcceleration_;
}

