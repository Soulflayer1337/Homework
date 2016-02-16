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

/**
 * \brief The GameClass class is a manager of the game.
 */
class GameClass : public QObject
{
    Q_OBJECT
public:
    explicit GameClass(QObject *parent = 0);

    /// \brief initalizes the game.
    /// Connects the keyboard input to the view.
    /// View is an output widget for the game.
    void startGame(QGraphicsView *view, Network *network);
    /// \brief generates landscape by using a set of rules.
    void generateLandscape(int width, int height);

    const Landscape *getLandscape() const;
    void setProjectile(Projectile *projectile);

signals:
    /// \brief emitted in the end of each frame
    void updated();
    /// \brief emitted when the collision of the projectile and a cannon was detected.
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
