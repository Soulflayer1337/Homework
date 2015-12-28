#include "landscape.h"

#include "gameclass.h"

Landscape::Landscape(GameClass *parent) :
    QObject(parent),
    gameClass_(parent),
    height_(0)
{
}

void Landscape::setHeight(int height)
{
    height_ = height;
}

void Landscape::setField(const QVector<int> &newField)
{
    field_ = newField;
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

