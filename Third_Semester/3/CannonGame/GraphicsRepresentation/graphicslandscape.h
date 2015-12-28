#pragma once

#include <QGraphicsItem>

class Landscape;

class GraphicsLandscape : public QGraphicsItem
{
public:
    explicit GraphicsLandscape(QGraphicsItem *parent = nullptr);

    void setModel(const Landscape *model);
    QRectF boundingRect() const Q_DECL_OVERRIDE;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
               QWidget *widget) Q_DECL_OVERRIDE;
    QPainterPath shape() const Q_DECL_OVERRIDE;
private:
    const Landscape *model_;
    QPainterPath path_;
};
