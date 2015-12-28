#include "graphicscannon.h"

#include <QPainter>
#include <QtMath>

#include "GameObjects/cannon.h"

GraphicsCannon::GraphicsCannon(QGraphicsItem *parent) :
    QGraphicsObject(parent),
    model_(nullptr)
{
    path_.moveTo(-17, 0);
    path_.lineTo(-20, -10);
    path_.lineTo(-13, -10);
    path_.lineTo(-7, -15);
    path_.lineTo(7, -15);
    path_.lineTo(13, -10);
    path_.lineTo(20, -10);
    path_.lineTo(17, 0);
    path_.closeSubpath();
}

void GraphicsCannon::setModel(Cannon *model)
{
    disconnect(model_);
    model_ = model;
    connect(model_, SIGNAL(updated()), this, SLOT(updatePosition()));
    updatePosition();
}

QRectF GraphicsCannon::boundingRect() const
{
    return (QRectF(-5, -15, 10, 5));
}

void GraphicsCannon::paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
                           QWidget *widget)
{
    float angle = qDegreesToRadians(float(model_->getAngleOfCannon()));
    painter->setPen(QPen(QBrush(Qt::black), 1));
    painter->setBrush(QColor(Qt::green).darker());
    painter->drawLine(0, -10, qCos(angle) * 15, -10 - qSin(angle) * 15);

    painter->drawPath(path_);
}

QPainterPath GraphicsCannon::shape() const
{
    return path_;
}

void GraphicsCannon::updatePosition()
{
    float xPosition = 0;
    float yPosition = 0;
    model_->getPosition(xPosition, yPosition);
    yPosition = -yPosition;
    setPos(xPosition, yPosition);
}
