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

GameClass::GameClass(QObject *parent) :
    QObject(parent),
    scene_(nullptr),

    timer_(nullptr),
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
}

void GameClass::startGame(QGraphicsView *view)
{
    view->setScene(scene_);
    connect(this, SIGNAL(updated()), view->viewport(), SLOT(update()));
    KeyboardManager *keyboardManager = new KeyboardManager(view);

    generateLandscape(798, 598);
    scene_->addItem(landscape_);

    firstCannon_ = new Cannon(landscape_, this);
    firstCannon_->setPosition(50);
    firstCannon_->setInputManager(keyboardManager);

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
        landscape_ = new Landscape(this);
    }
    landscape_->setField(points);
    landscape_->setHeight(height);
}

//////////////////////////////////////////////////////////////////////////////
//                        Getters/Setters section
//////////////////////////////////////////////////////////////////////////////
void GameClass::setLandscape(Landscape *landscape)
{
    landscape_ = landscape;
}

const Landscape *GameClass::getLandscape() const
{
    return landscape_;
}

void GameClass::setProjectile(Projectile *projectile)
{
    firstCannon_->getInputManager()->blockSignals(true);
    projectile_ = projectile;
}

//////////////////////////////////////////////////////////////////////////////
//                                  Update
//////////////////////////////////////////////////////////////////////////////
void GameClass::update()
{
    firstCannon_->update();

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
            firstCannon_->getInputManager()->blockSignals(false);
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
        explosion_->update();
    }

    emit updated();
}

void GameClass::explosionOver()
{
    qSafeDelete(explosion_);
    firstCannon_->getInputManager()->blockSignals(false);
}
