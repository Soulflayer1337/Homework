#pragma once

#include <QWidget>

class GameClass;
class QGraphicsView;
class QGraphicsScene;
class Cannon;

class CannonGameWidget : public QWidget
{
    Q_OBJECT

public:
    explicit CannonGameWidget(QWidget *parent = 0);
    ~CannonGameWidget();

private:
    QGraphicsView *graphicsView_;
    QGraphicsScene *scene_;

    GameClass *gameClass_;
    Cannon *cannon_;
};
