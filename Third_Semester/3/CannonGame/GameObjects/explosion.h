#pragma once

#include <QGraphicsObject>

#include "GameObjects/Projectiles/projectile.h"

/**
 * \brief The Explosion class is a model of the explosion
 */
class Explosion : public QGraphicsObject
{
    Q_OBJECT
public:
    /// \param radius is a maximum radius of the explosion
    explicit Explosion(int radius, Projectile *parent);

    QRectF boundingRect() const Q_DECL_OVERRIDE;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
               QWidget *widget) Q_DECL_OVERRIDE;
    QPainterPath shape() const Q_DECL_OVERRIDE;

    /// \brief getRadius method gets the maximum radius
    int getRadius() const;
    /// \brief getCurrentRadius gets the current radius of the explosion
    /// Current radius increases each frame
    float getCurrentRadius() const;
    /// \brief update method updates the current radius.
    /// explosionOver signal is emitted by this method.
    void update();

signals:
    void explosionOver();

private:
    int radius_;
    int turnsCounter_;
    const int turnsToDisapper_;
};

