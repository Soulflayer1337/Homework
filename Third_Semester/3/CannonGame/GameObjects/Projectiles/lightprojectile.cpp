#include "lightprojectile.h"

#include "GameObjects/explosion.h"

LightProjectile::LightProjectile(Cannon *parent) :
    Projectile(parent, 8.0f)
{
    radius_ = 2;
}

void LightProjectile::update()
{
    xPosition_ += xAcceleration_;
    yPosition_ += yAcceleration_;
    yAcceleration_ -= 0.3f;
    xAcceleration_ += (xAcceleration_ > 0 ? 0.1f : -0.1f);
    setPos(xPosition_, -yPosition_);
}

Explosion *LightProjectile::getExplosion()
{
    deleteLater();
    return new Explosion(10, this);
}

