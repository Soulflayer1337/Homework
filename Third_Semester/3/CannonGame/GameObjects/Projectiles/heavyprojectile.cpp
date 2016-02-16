#include "heavyprojectile.h"

#include "GameObjects/explosion.h"

HeavyProjectile::HeavyProjectile(Cannon *parent) :
    Projectile(parent, 5.0f)
{
    radius_ = 4;
}

void HeavyProjectile::update()
{
    xPosition_ += xAcceleration_;
    yPosition_ += yAcceleration_;
    yAcceleration_ -= 0.3f;
    setPos(xPosition_, -yPosition_);
}

Explosion *HeavyProjectile::getExplosion()
{
    deleteLater();
    return new Explosion(50, this);
}

