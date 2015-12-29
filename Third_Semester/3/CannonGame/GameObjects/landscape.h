#pragma once

#include <QGraphicsObject>
#include <QVector>

class GameClass;

class Landscape : public QGraphicsObject
{
    Q_OBJECT
public:
    explicit Landscape();

    QRectF boundingRect() const Q_DECL_OVERRIDE;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
               QWidget *widget) Q_DECL_OVERRIDE;
    QPainterPath shape() const Q_DECL_OVERRIDE;

    void setHeight(int height);

    void setField(const QVector<int> &newField);
    const QVector<int> &getField() const;

    void setHeightAt(int position, uint value);
    int getHeightAt(int position) const;

    int getWidth() const;
    int getHeight() const;

private:
    QPainterPath path_;
    QVector<int> field_;
    int height_;
};
