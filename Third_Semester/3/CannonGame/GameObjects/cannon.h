#pragma once

#include <QGraphicsObject>
#include <InputManager/inputmanager.h>

class GameClass;

class Cannon : public QGraphicsObject
{
    Q_OBJECT
public:
    explicit Cannon(QGraphicsItem *parent, GameClass *gameClass);
    ~Cannon();

    void update();
    QRectF boundingRect() const Q_DECL_OVERRIDE;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
               QWidget *widget) Q_DECL_OVERRIDE;
    QPainterPath shape() const Q_DECL_OVERRIDE;

    void setInputManager(InputManager *manager);
    InputManager *getInputManager() const;
    void setFacingRight(bool facingRight = true);
    bool isFacingRight() const;
    void setPosition(int xPosition);
    void getPosition(float &xPosition, float &yPosition) const;

    float getAngleOfCannon() const;

private slots:
    void moveRight();
    void moveLeft();
    void angleUp();
    void angleDown();
    void changeProjectilesType();
    void shoot();
    void stopAction();

private:
    GameClass *gameClass_;
    InputManager *inputManager_;
    QPainterPath path_;

    int deltaX_;
    int deltaAngle_;
    bool isLightProjectile_;

    bool facingRight_;
    int xPosition_;
    int yPosition_;

    int angleOfCannon_;
};
