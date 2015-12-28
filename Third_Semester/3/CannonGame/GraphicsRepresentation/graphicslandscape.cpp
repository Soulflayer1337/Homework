#include "graphicslandscape.h"

#include <QPainter>

#include "GameObjects/landscape.h"

GraphicsLandscape::GraphicsLandscape(QGraphicsItem *parent) :
    QGraphicsItem(parent),
    model_(nullptr)
{
}

void GraphicsLandscape::setModel(const Landscape *model)
{
    model_ = model;

    QVector<int> field = model_->getField();

    qreal height = model_->getHeight();
    setPos(0, height);

    path_.moveTo(model_->getWidth() - 1, -1);
    path_.lineTo(0, -1);
    path_.lineTo(0, -field.first());

    for (int i = 0; i < field.size() - 1; i++)
    {
        path_.lineTo(i + 1, -field.at(i + 1));
    }

    path_.closeSubpath();
}

QRectF GraphicsLandscape::boundingRect() const
{
    return (QRectF(0, 0, model_->getWidth(), model_->getHeight()));
}

void GraphicsLandscape::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setPen(QPen(QBrush(Qt::green), 2));
    painter->setBrush(QColor(150, 75, 0));
    painter->drawPath(path_);
}

QPainterPath GraphicsLandscape::shape() const
{
    return path_;
}
