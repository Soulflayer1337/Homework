#pragma once

#include <QGraphicsObject>

class Cannon;

class GraphicsCannon : public QGraphicsObject
{
    Q_OBJECT
public:
    explicit GraphicsCannon(QGraphicsItem *parent = nullptr);

    void setModel(Cannon *model);
    QRectF boundingRect() const Q_DECL_OVERRIDE;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
               QWidget *widget) Q_DECL_OVERRIDE;
    QPainterPath shape() const Q_DECL_OVERRIDE;

private slots:
    void updatePosition();

private:
    Cannon *model_;
    QPainterPath path_;
};
