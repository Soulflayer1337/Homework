#pragma once

#include <QGraphicsObject>
#include <InputManager/inputmanager.h>

class GameClass;

/**
 * \brief The Cannon class is a model of a cannon and is manipulated by InputManager
 */
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

    /// \brief connects signals of manager and slots of the Cannon
    void setInputManager(InputManager *manager);
    InputManager *getInputManager() const;

    /// \brief setFacingRight is used to correct the dirrection of the cannon.
    /// It affects the angle in radians
    void setFacingRight(bool facingRight = true);
    bool isFacingRight() const;
    /// \brief setPosition is used to set xPosition of the cannon.
    /// The cannon get yPosition automatically by using the gameClass
    void setPosition(int xPosition);
    void getPosition(float &xPosition, float &yPosition) const;
    /// \param angle should be in degrees
    void setAngleOfCannon(int angle);

    /// \brief getAngleOfCannon returns the angle of cannon in radians
    /// The value depends on the direction(facingRight_) of the Cannon
    float getAngleOfCannon() const;
    /// \brief getAngleOfCannonDegrees returns the angle of cannon in degrees
    int getAngleOfCannonDegrees() const;

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
