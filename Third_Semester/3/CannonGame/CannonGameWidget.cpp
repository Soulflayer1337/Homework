#include "CannonGameWidget.h"

#include <QGraphicsView>
#include <QPushButton>
#include <QGridLayout>

#include "InputManager/keyboardmanager.h"
#include "gameclass.h"
#include "GameObjects/landscape.h"
#include "GameObjects/cannon.h"

CannonGameWidget::CannonGameWidget(QWidget *parent) :
    QWidget(parent)
{
    setFixedSize(800, 600);

    GameClass *gameClass_ = new GameClass(this);
    QGraphicsView *graphicsView_ = new QGraphicsView;

    QGridLayout *layout = new QGridLayout;
    layout->addWidget(graphicsView_);
    layout->setMargin(0);

    setLayout(layout);
    gameClass_->startGame(graphicsView_);
}

CannonGameWidget::~CannonGameWidget()
{
}
