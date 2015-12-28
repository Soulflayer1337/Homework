#include "lightprojectile.h"

LightProjectile::LightProjectile(Cannon *parent) :
    Projectile(parent, 10.0f)
{
    radius_ = 2;
}

void LightProjectile::update()
{
    xPosition_ += xAcceleration_;
    yPosition_ += yAcceleration_;
    yAcceleration_ -= 1.0f;
    xAcceleration_ += 1.0f;

    emit updated();
}

void LightProjectile::explode()
{
    deleteLater();
}

