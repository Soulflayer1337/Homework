#pragma once

#include "projectile.h"

class HeavyProjectile : public Projectile
{
    Q_OBJECT
public:
    explicit HeavyProjectile(Cannon *parent);

    void update() override;
    Explosion *getExplosion() override;
};
