#pragma once

#include <QGraphicsObject>

#include "GameObjects/Projectiles/projectile.h"

class Explosion : public QGraphicsObject
{
    Q_OBJECT
public:
    explicit Explosion(int radius, Projectile *parent);

    QRectF boundingRect() const Q_DECL_OVERRIDE;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
               QWidget *widget) Q_DECL_OVERRIDE;
    QPainterPath shape() const Q_DECL_OVERRIDE;

    int getRadius() const;
    float getCurrentRadius() const;
    void update();

signals:
    void explosionOver();

private:
    int radius_;
    int turnsCounter_;
    const int turnsToDisapper_;
};

