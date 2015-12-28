#pragma once

#include <QGraphicsObject>

class Cannon;
class Explosion;

class Projectile : public QGraphicsObject
{
    Q_OBJECT
public:
    explicit Projectile(Cannon *parent, float baseAcceleration = 0.0f);

    QRectF boundingRect() const Q_DECL_OVERRIDE;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
               QWidget *widget) Q_DECL_OVERRIDE;
    QPainterPath shape() const Q_DECL_OVERRIDE;

    virtual void update() = 0;
    virtual Explosion *getExplosion() = 0;

    int getRadius() const;
    void getPosition(int &xPosition, int &yPosition) const;
    void getAcceleration(float &xAcceleration, float &yAcceleration) const;

protected:
    int radius_;

    float xPosition_;
    float yPosition_;

    float xAcceleration_;
    float yAcceleration_;
};
