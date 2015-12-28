#include "heavyprojectile.h"

#include "GameObjects/cannon.h"

HeavyProjectile::HeavyProjectile(Cannon *parent) :
    Projectile(parent, 5.0f)
{
    radius_ = 4;
}

void HeavyProjectile::update()
{
    xPosition_ += xAcceleration_;
    yPosition_ += yAcceleration_;
    yAcceleration_ -= 1.0f;
    emit updated();
}

void HeavyProjectile::explode()
{
    deleteLater();
}

