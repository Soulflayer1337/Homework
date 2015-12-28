#pragma once

#include <QGraphicsObject>

class Projectile;

class GraphicsProjectile : public QGraphicsObject
{
    Q_OBJECT
public:
    explicit GraphicsProjectile(QGraphicsItem *parent = nullptr);

    void setModel(Projectile *model);
    QRectF boundingRect() const Q_DECL_OVERRIDE;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
               QWidget *widget) Q_DECL_OVERRIDE;
    QPainterPath shape() const Q_DECL_OVERRIDE;

private slots:
    void updatePosition();

private:
    Projectile *model_;
};
