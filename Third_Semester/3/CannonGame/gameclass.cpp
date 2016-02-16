#include "gameclass.h"

#include <QGraphicsView>
#include <QGraphicsScene>

#include <QTimer>
#include <QTime>
#include <QVector>

#include "GameObjects/landscape.h"
#include "GameObjects/cannon.h"
#include "GameObjects/Projectiles/projectile.h"
#include "GameObjects/explosion.h"
#include "InputManager/keyboardmanager.h"
#include "util.h"

#include "Network/client.h"
#include "Network/server.h"

GameClass::GameClass(QObject *parent) :
    QObject(parent),
    scene_(nullptr),

    isFirstTurn_(true),

    timer_(nullptr),
    loop_(new QEventLoop(this)),

    landscape_(nullptr),
    firstCannon_(nullptr),
    secondCannon_(nullptr),
    projectile_(nullptr),
    explosion_(nullptr)
{
    scene_ = new QGraphicsScene(0, 0, 798, 598, this);
    scene_->setBackgroundBrush(QColor(128, 208, 255));

    qsrand(QDateTime::currentMSecsSinceEpoch());
    timer_ = new QTimer(this);
    connect(timer_, SIGNAL(timeout()), this, SLOT(update()));
    connect(this, SIGNAL(gameOver(QString)), this, SLOT(onGameOver()));
}

void GameClass::startGame(QGraphicsView *view, Network *network)
{
    network_ = network;
    view->setScene(scene_);
    connect(this, SIGNAL(updated()), view->viewport(), SLOT(update()));
    KeyboardManager *keyboardManager = new KeyboardManager(view);

    if (dynamic_cast<Server *>(network))
    {
        Server *server = static_cast<Server *>(network);
        generateLandscape(798, 598);
        server->sendLandscape(landscape_);

        firstCannon_ = new Cannon(landscape_, this);
        secondCannon_ = new Cannon(landscape_, this);
        firstCannon_->setPosition(50);
        secondCannon_->setPosition(landscape_->getWidth() - 50);
        secondCannon_->setFacingRight(false);
    }
    else
    {
        Client *client = static_cast<Client *>(network);
        connect(client, SIGNAL(gotLandscape(Landscape *)),
                this, SLOT(setLandscape(Landscape*)));
        loop_->exec();

        firstCannon_ = new Cannon(landscape_, this);
        secondCannon_ = new Cannon(landscape_, this);
        secondCannon_->setPosition(50);
        firstCannon_->setPosition(landscape_->getWidth() - 50);
        firstCannon_->setFacingRight(false);

        isFirstTurn_ = false;
    }
    scene_->addItem(landscape_);

    firstCannon_->setInputManager(keyboardManager);
    network->initInputManager(secondCannon_);
    network_->observeInputManager(firstCannon_);

    if (isFirstTurn_)
    {
        secondCannon_->getInputManager()->blockSignals(true);
    }
    else
    {
        firstCannon_->getInputManager()->blockSignals(true);
    }

    timer_->start(17);
}

void GameClass::generateLandscape(int width, int height)
{
    float yPosition = 150 + qrand() % 101;
    QVector<int> points;
    points.append(yPosition);

    int delta = (qrand() % 21 - 10) * 2;

    for (int i = 1; i < width; i++)
    {
        yPosition += delta * 0.1f;
        points.append(yPosition);

        int chanceOfPlus = 0;
        if (abs(delta) <= 5)
        {
            chanceOfPlus = 50;
        }
        else if (abs(delta) <= 8)
        {
            chanceOfPlus = 30;
        }
        else if (abs(delta) <= 12)
        {
            chanceOfPlus = 15;
        }
        else if (abs(delta) <= 16)
        {
            chanceOfPlus = 5;
        }

        if (delta < 0)
        {
            chanceOfPlus = 100 - chanceOfPlus;
        }

        if (qrand() % 100 < chanceOfPlus)
        {
            delta += 2;
        }
        else
        {
            delta -= 2;
        }

        if (yPosition <= 50)
        {
            delta = 5;
        }
        else if (yPosition >= 300)
        {
            delta = -5;
        }
    }

    if (!landscape_)
    {
        landscape_ = new Landscape;
    }
    landscape_->setField(points);
    landscape_->setHeight(height);
}

//////////////////////////////////////////////////////////////////////////////
//                        Getters/Setters section
//////////////////////////////////////////////////////////////////////////////
void GameClass::setLandscape(Landscape *landscape)
{
    Client *client = static_cast<Client *>(network_);
    disconnect(client, SIGNAL(gotLandscape(Landscape*)),
               this, SLOT(setLandscape(Landscape*)));
    landscape_ = landscape;
    loop_->exit();
}

const Landscape *GameClass::getLandscape() const
{
    return landscape_;
}

void GameClass::setProjectile(Projectile *projectile)
{
    projectile_ = projectile;
    firstCannon_->getInputManager()->blockSignals(true);
    secondCannon_->getInputManager()->blockSignals(true);
    isFirstTurn_ ^= true;
}

//////////////////////////////////////////////////////////////////////////////
//                                  Update
//////////////////////////////////////////////////////////////////////////////
void GameClass::update()
{
    firstCannon_->update();
    secondCannon_->update();

    if (projectile_)
    {
        projectile_->update();

        // Check if in scene
        int xPosition = 0;
        int yPosition = 0;

        projectile_->getPosition(xPosition, yPosition);

        if (xPosition < 0 || xPosition > landscape_->getWidth())
        {
            qSafeDelete(projectile_);
            if (isFirstTurn_)
            {
                firstCannon_->getInputManager()->blockSignals(false);
            }
            else
            {
                secondCannon_->getInputManager()->blockSignals(false);
            }
        }
        else if (!projectile_->collidingItems().isEmpty())
        {
            explosion_ = projectile_->getExplosion();
            connect(explosion_, SIGNAL(explosionOver()), this, SLOT(explosionOver()));
            projectile_ = nullptr;
        }
    }
    else if (explosion_)
    {
        int gameOverDetector = 0;
        if (explosion_->collidesWithItem(firstCannon_))
        {
            gameOverDetector |= 1;
        }
        else if (explosion_->collidesWithItem(secondCannon_))
        {
            gameOverDetector |= 2;
        }

        if (gameOverDetector)
        {
            QString gameOverText;
            if (gameOverDetector == 1)
            {
                gameOverText = "Lose!";
            }
            else if (gameOverDetector == 2)
            {
                gameOverText = "Win!";
            }
            else
            {
                gameOverText = "Draw!";
            }
            emit gameOver(gameOverText);
        }

        explosion_->update();
    }

    emit updated();
}

void GameClass::explosionOver()
{
    qSafeDelete(explosion_);

    if (isFirstTurn_)
    {
        firstCannon_->getInputManager()->blockSignals(false);
    }
    else
    {
        secondCannon_->getInputManager()->blockSignals(false);
    }
}

void GameClass::onGameOver()
{
    deleteLater();
}
