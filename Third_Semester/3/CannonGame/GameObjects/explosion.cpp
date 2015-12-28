#include "explosion.h"

#include <QPainter>
#include <QtMath>

#include "gameclass.h"

Explosion::Explosion(int radius, Projectile *parent) :
    QGraphicsObject(parent->parentObject()),
    radius_(radius),
    turnsCounter_(0),
    turnsToDisapper_(25)
{
    setPos(parent->pos());
}

//////////////////////////////////////////////////////////////////////////////
//                            Drawing section
//////////////////////////////////////////////////////////////////////////////
QRectF Explosion::boundingRect() const
{
    float radius = getCurrentRadius();
    return (QRectF(-radius, -radius, 2 * radius, 2 * radius));
}

void Explosion::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setBrush(QColor(255, 240, 160));
    painter->setPen(QPen(QColor(255, 140, 0), 2));
    painter->drawEllipse(boundingRect());
}

QPainterPath Explosion::shape() const
{
    QPainterPath path;
    path.addEllipse(boundingRect());
    return path;
}

//////////////////////////////////////////////////////////////////////////////
//                        Getters/Setters section
//////////////////////////////////////////////////////////////////////////////
int Explosion::getRadius() const
{
    return radius_;
}

float Explosion::getCurrentRadius() const
{
    int multiplier = qMax(9, turnsCounter_);
    return (qSqrt(qreal(radius_ * (multiplier + 1)) / turnsToDisapper_));
}

void Explosion::update()
{
    turnsCounter_++;

    if (turnsCounter_ == turnsToDisapper_)
    {
        emit explosionOver();
    }
}

