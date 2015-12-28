#pragma once

#include "projectile.h"

class LightProjectile : public Projectile
{
    Q_OBJECT
public:
    explicit LightProjectile(Cannon *parent);

    void update() override;
    Explosion *getExplosion() override;
};
