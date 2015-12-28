#pragma once

#include <QObject>

class Landscape;
class Cannon;
class Projectile;
class QTimer;

class GameClass : public QObject
{
    Q_OBJECT
public:
    explicit GameClass(QObject *parent = 0);

    void startGame();
    void generateLandscape(int width, int height);

    ///////////////////////////////////////////
    //        Setters/Getters section
    ///////////////////////////////////////////
    void setLandscape(Landscape *landscape);
    const Landscape *getLandscape() const;
    const Projectile *getProjectile() const;
    void setFirstCannon(Cannon *cannon);
    void setSecondCannon(Cannon *cannon);
    void setProjectile(Projectile *projectile);

signals:
    void updated();

private slots:
    void update();

private:
    QTimer *timer_;

    Landscape *landscape_;
    Cannon *firstCannon_;
    Cannon *secondCannon_;
    Projectile *projectile_;
};
