#include "CannonGameWidget.h"

#include <QGraphicsScene>
#include <QGraphicsView>
#include <QMessageBox>
#include <QPushButton>
#include <QGridLayout>

#include <QKeyEvent>

#include "InputManager/keyboardmanager.h"
#include "gameclass.h"
#include "GraphicsRepresentation/graphicslandscape.h"
#include "GraphicsRepresentation/graphicscannon.h"
#include "GameObjects/cannon.h"

CannonGameWidget::CannonGameWidget(QWidget *parent) :
    QWidget(parent),
    graphicsView_(nullptr),
    scene_(nullptr),

    gameClass_(nullptr)
{
    setFixedSize(800, 600);

    scene_ = new QGraphicsScene(0, 0, 798, 598, this);
    scene_->setBackgroundBrush(QColor(128, 208, 255));
    graphicsView_ = new QGraphicsView(scene_);
    KeyboardManager *keyboardManager = new KeyboardManager(graphicsView_);

    gameClass_ = new GameClass(this);
    gameClass_->generateLandscape(798, 598);
    connect(gameClass_, SIGNAL(updated()), graphicsView_->viewport(), SLOT(update()));
    GraphicsLandscape *landscape = new GraphicsLandscape;
    landscape->setModel(gameClass_->getLandscape());
    scene_->addItem(landscape);

    cannon_ = new Cannon(gameClass_);
    cannon_->setPosition(50);
    GraphicsCannon *cannon = new GraphicsCannon(landscape);
    cannon->setModel(cannon_);
    cannon_->setInputManager(keyboardManager);
    gameClass_->setFirstCannon(cannon_);

    QGridLayout *layout = new QGridLayout;
    layout->addWidget(graphicsView_);
    layout->setMargin(0);

    setLayout(layout);
    gameClass_->startGame();
}

CannonGameWidget::~CannonGameWidget()
{
}
