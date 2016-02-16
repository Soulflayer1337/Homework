#include "projectile.h"

#include <QPainter>
#include <QtMath>

#include "gameclass.h"
#include "GameObjects/cannon.h"
#include "GameObjects/landscape.h"

Projectile::Projectile(Cannon *parent, float baseAcceleration) :
    QGraphicsObject(parent->parentItem()),
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
}

//////////////////////////////////////////////////////////////////////////////
//                            Drawing section
//////////////////////////////////////////////////////////////////////////////
QRectF Projectile::boundingRect() const
{
    return (QRectF(-radius_, -radius_, 2 * radius_, 2 * radius_));
}

void Projectile::paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
                               QWidget *widget)
{
    painter->setBrush(QColor(45, 80, 5));
    painter->setPen(QPen(Qt::black, 1));
    painter->drawEllipse(boundingRect());
}

QPainterPath Projectile::shape() const
{
    QPainterPath path;
    path.addEllipse(boundingRect());
    return path;
}

//////////////////////////////////////////////////////////////////////////////
//                        Getters/Setters section
//////////////////////////////////////////////////////////////////////////////
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

