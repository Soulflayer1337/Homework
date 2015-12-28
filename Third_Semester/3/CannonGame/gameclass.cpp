#include "gameclass.h"

#include <QTimer>
#include <QTime>
#include <QVector>

#include "GameObjects/landscape.h"
#include "GameObjects/cannon.h"
#include "GameObjects/Projectiles/projectile.h"
#include "util.h"

GameClass::GameClass(QObject *parent) :
    QObject(parent),

    timer_(nullptr),
    landscape_(nullptr),
    firstCannon_(nullptr),
    secondCannon_(nullptr),
    projectile_(nullptr)
{
    qsrand(QDateTime::currentMSecsSinceEpoch());
    timer_ = new QTimer(this);
    connect(timer_, SIGNAL(timeout()), this, SLOT(update()));
}

void GameClass::startGame()
{
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

void GameClass::setLandscape(Landscape *landscape)
{
    landscape_ = landscape;
}

const Landscape *GameClass::getLandscape() const
{
    return landscape_;
}

const Projectile *GameClass::getProjectile() const
{
    return projectile_;
}

void GameClass::setFirstCannon(Cannon *cannon)
{
    firstCannon_ = cannon;
}

void GameClass::setSecondCannon(Cannon *cannon)
{
    secondCannon_ = cannon;
}

void GameClass::setProjectile(Projectile *projectile)
{
    projectile_ = projectile;
}

void GameClass::update()
{
    firstCannon_->update();

    if (projectile_)
    {
        projectile_->update();
    }

    emit updated();
}
