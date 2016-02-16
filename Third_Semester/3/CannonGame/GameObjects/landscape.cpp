#include "landscape.h"

#include <QPainter>

#include "gameclass.h"

Landscape::Landscape() :
    QGraphicsObject(nullptr),
    height_(0)
{
}

//////////////////////////////////////////////////////////////////////////////
//                            Drawing section
//////////////////////////////////////////////////////////////////////////////
QRectF Landscape::boundingRect() const
{
    return (QRectF(0, -height_, getWidth(), height_));
}

void Landscape::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setPen(QPen(QBrush(Qt::green), 2));
    painter->setBrush(QColor(150, 75, 0));
    painter->drawPath(path_);
}

QPainterPath Landscape::shape() const
{
    return path_;
}

////////////////////////////////////////////////////////////////////////
///                     Getters/Setters section
////////////////////////////////////////////////////////////////////////
void Landscape::setHeight(int height)
{
    height_ = height;
    setPos(0, height_);
}

void Landscape::setField(const QVector<int> &newField)
{
    field_ = newField;
    path_ = QPainterPath();

    path_.moveTo(getWidth() - 1, -1);
    path_.lineTo(0, -1);
    path_.lineTo(0, -field_.first());

    for (int i = 0; i < field_.size() - 1; i++)
    {
        path_.lineTo(i + 1, -field_.at(i + 1));
    }

    path_.closeSubpath();
}

const QVector<int> &Landscape::getField() const
{
    return field_;
}

void Landscape::setHeightAt(int position, uint value)
{
    if (value < field_.size())
    {
        field_.replace(position, value);
    }
}

int Landscape::getHeightAt(int position) const
{
    if (position >= 0 && position <= field_.size())
    {
        return field_.at(position);
    }
    else
    {
        return -1;
    }
}

int Landscape::getWidth() const
{
    return field_.size();
}

int Landscape::getHeight() const
{
    return height_;
}

