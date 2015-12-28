#include "graphicsprojectile.h"

#include <QPainter>

#include "GameObjects/Projectiles/projectile.h"

GraphicsProjectile::GraphicsProjectile(QGraphicsItem *parent) :
    QGraphicsObject(parent),
    model_(nullptr)
{
}

void GraphicsProjectile::setModel(Projectile *model)
{
    disconnect(model_);
    model_ = model;
    connect(model_, SIGNAL(updated()), this, SLOT(updatePosition()));
    connect(model_, SIGNAL(destroyed()), this, SLOT(deleteLater()));
    updatePosition();
}

QRectF GraphicsProjectile::boundingRect() const
{
    int radius = model_->getRadius();
    return (QRectF(-radius, -radius, 2 * radius, 2 * radius));
}

void GraphicsProjectile::paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
                               QWidget *widget)
{
    painter->setBrush(QColor(45, 80, 5));
    painter->setPen(QPen(Qt::black, 1));
    painter->drawEllipse(boundingRect());
}

QPainterPath GraphicsProjectile::shape() const
{
    QPainterPath path;
    path.addEllipse(boundingRect());
    return path;
}

void GraphicsProjectile::updatePosition()
{
    int xPosition = 0;
    int yPosition = 0;
    model_->getPosition(xPosition, yPosition);
    setPos(xPosition, yPosition);
}

