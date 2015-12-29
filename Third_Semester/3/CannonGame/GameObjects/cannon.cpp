#include "cannon.h"

#include <QPainter>
#include <QtMath>

#include "landscape.h"
#include "gameclass.h"
#include "GameObjects/Projectiles/projectile.h"
#include "GameObjects/Projectiles/heavyProjectile.h"
#include "GameObjects/Projectiles/lightProjectile.h"

Cannon::Cannon(QGraphicsItem *parent, GameClass *gameClass) :
    QGraphicsObject(parent),
    gameClass_(gameClass),
    inputManager_(nullptr),

    deltaX_(0),
    deltaAngle_(0),
    isLightProjectile_(true),

    facingRight_(true),
    xPosition_(0),
    yPosition_(0),
    angleOfCannon_(45)
{
    path_.moveTo(-17, 0);
    path_.lineTo(-20, -10);
    path_.lineTo(-13, -10);
    path_.lineTo(-7, -15);
    path_.lineTo(7, -15);
    path_.lineTo(13, -10);
    path_.lineTo(20, -10);
    path_.lineTo(17, 0);
    path_.closeSubpath();
}

Cannon::~Cannon()
{
}

void Cannon::update()
{
    const Landscape *landscape = gameClass_->getLandscape();

    if (deltaX_ != 0 && ((deltaX_ > 0) ^ facingRight_))
    {
        facingRight_ ^= true;
    }
    else
    {
        xPosition_ += deltaX_;
        if (xPosition_ >= landscape->getWidth() - 20)
        {
            xPosition_ = landscape->getWidth() - 21;
        }
        else if (xPosition_ < 20)
        {
            xPosition_ = 20;
        }
    }

    yPosition_ = landscape->getHeightAt(xPosition_);

    angleOfCannon_ += deltaAngle_;

    if (angleOfCannon_ < 10)
    {
        angleOfCannon_ = 10;
    }
    else if (angleOfCannon_ > 80)
    {
        angleOfCannon_ = 80;
    }
    setPos(xPosition_, -yPosition_);
}

//////////////////////////////////////////////////////////////////////////////
//                            Drawing section
//////////////////////////////////////////////////////////////////////////////
QRectF Cannon::boundingRect() const
{
    return (QRectF(-5, -15, 10, 5));
}

void Cannon::paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
                           QWidget *widget)
{
    float angle = getAngleOfCannon();
    painter->setPen(QPen(QBrush(Qt::black), 1));
    painter->setBrush(QColor(Qt::green).darker());
    painter->drawLine(0, -10, qCos(angle) * 15, -10 - qSin(angle) * 15);

    painter->drawPath(path_);
}

QPainterPath Cannon::shape() const
{
    return path_;
}

//////////////////////////////////////////////////////////////////////////////
//                        Getters/Setters section
//////////////////////////////////////////////////////////////////////////////
void Cannon::setInputManager(InputManager *manager)
{
    if (inputManager_)
    {
        disconnect(inputManager_);
    }
    inputManager_ = manager;

    connect(manager, SIGNAL(moveRightPressed()), this, SLOT(moveRight()));
    connect(manager, SIGNAL(moveLeftPressed()),  this, SLOT(moveLeft()));
    connect(manager, SIGNAL(angleUpPressed()),   this, SLOT(angleUp()));
    connect(manager, SIGNAL(angleDownPressed()), this, SLOT(angleDown()));
    connect(manager, SIGNAL(shootPressed()),     this, SLOT(shoot()));
    connect(manager, SIGNAL(changePressed()),    this, SLOT(changeProjectilesType()));
    connect(manager, SIGNAL(buttonReleased()),   this, SLOT(stopAction()));
}

InputManager *Cannon::getInputManager() const
{
    return inputManager_;
}

void Cannon::setFacingRight(bool facingRight)
{
    facingRight_ = facingRight;
}

bool Cannon::isFacingRight() const
{
    return facingRight_;
}

void Cannon::setPosition(int xPosition)
{
    xPosition_ = xPosition;
    yPosition_ = gameClass_->getLandscape()->getHeightAt(xPosition_);
    setPos(xPosition_, -yPosition_);
}

void Cannon::getPosition(float &xPosition, float &yPosition) const
{
    xPosition = xPosition_;
    yPosition = yPosition_;
}

void Cannon::setAngleOfCannon(int angle)
{
    angleOfCannon_ = angle;
}

float Cannon::getAngleOfCannon() const
{
    return qDegreesToRadians(float(isFacingRight() ? angleOfCannon_ : 180 - angleOfCannon_));
}

int Cannon::getAngleOfCannonDegrees() const
{
    return angleOfCannon_;
}

//////////////////////////////////////////////////////////////////////////////
//                        Handle input section
//////////////////////////////////////////////////////////////////////////////
void Cannon::moveRight()
{
    stopAction();
    deltaX_ = 2;
}

void Cannon::moveLeft()
{
    stopAction();
    deltaX_ = -2;
}

void Cannon::angleUp()
{
    stopAction();
    deltaAngle_ = 2;
}

void Cannon::angleDown()
{
    stopAction();
    deltaAngle_ = -2;
}

void Cannon::changeProjectilesType()
{
    stopAction();
    isLightProjectile_ ^= true;
}

void Cannon::shoot()
{
    stopAction();
    Projectile *projectile = nullptr;

    if (isLightProjectile_)
    {
        projectile = new LightProjectile(this);
    }
    else
    {
        projectile = new HeavyProjectile(this);
    }

    gameClass_->setProjectile(projectile);
}

void Cannon::stopAction()
{
    deltaX_ = 0;
    deltaAngle_ = 0;
}
