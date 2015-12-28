#pragma once

#include <QObject>

class QGraphicsView;
class QGraphicsScene;

class Landscape;
class Cannon;
class Projectile;
class Explosion;
class QTimer;

class GameClass : public QObject
{
    Q_OBJECT
public:
    explicit GameClass(QObject *parent = 0);

    void startGame(QGraphicsView *view);
    void generateLandscape(int width, int height);

    ///////////////////////////////////////////
    //        Setters/Getters section
    ///////////////////////////////////////////
    void setLandscape(Landscape *landscape);
    const Landscape *getLandscape() const;
    void setProjectile(Projectile *projectile);

signals:
    void updated();

private slots:
    void update();
    void explosionOver();

private:
    QGraphicsScene *scene_;

    QTimer *timer_;

    Landscape *landscape_;
    Cannon *firstCannon_;
    Cannon *secondCannon_;
    Projectile *projectile_;
    Explosion *explosion_;
};
