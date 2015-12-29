#pragma once

#include <QObject>
#include <QEventLoop>

class QGraphicsView;
class QGraphicsScene;
class QTimer;

class Landscape;
class Cannon;
class Projectile;
class Explosion;
class Network;

class GameClass : public QObject
{
    Q_OBJECT
public:
    explicit GameClass(QObject *parent = 0);

    void startGame(QGraphicsView *view, Network *network);
    void generateLandscape(int width, int height);

    ///////////////////////////////////////////
    //        Setters/Getters section
    ///////////////////////////////////////////
    const Landscape *getLandscape() const;
    void setProjectile(Projectile *projectile);

signals:
    void updated();
    void gameOver(const QString &string);

private slots:
    void setLandscape(Landscape *landscape);
    void update();
    void explosionOver();
    void onGameOver();

private:
    QGraphicsScene *scene_;
    Network *network_;
    bool isFirstTurn_;

    QTimer *timer_;

    QEventLoop *loop_;
    Landscape *landscape_;
    Cannon *firstCannon_;
    Cannon *secondCannon_;
    Projectile *projectile_;
    Explosion *explosion_;
};
