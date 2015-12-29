#include "CannonGameMainWindow.h"

#include <QGraphicsView>
#include <QPushButton>
#include <QLineEdit>
#include <QLabel>
#include <QGridLayout>
#include <QMessageBox>
#include <QStatusBar>

#include "InputManager/keyboardmanager.h"
#include "gameclass.h"
#include "GameObjects/landscape.h"
#include "GameObjects/cannon.h"

#include "connectserverdialog.h"

#include "Network/client.h"
#include "Network/server.h"

CannonGameMainWindow::CannonGameMainWindow(QWidget *parent) :
    QMainWindow(parent),
    network_(nullptr)
{
}

bool CannonGameMainWindow::initNetwork()
{
    QMessageBox *networkDialog = new QMessageBox(this);
    networkDialog->setText("Choose network type");

    QPushButton *clientButton = networkDialog->addButton("Client", QMessageBox::ActionRole);
    QPushButton *serverButton = networkDialog->addButton("Server", QMessageBox::ActionRole);
    networkDialog->addButton(QMessageBox::Cancel);

    networkDialog->exec();
    QAbstractButton *clickedButton = networkDialog->clickedButton();
    networkDialog->deleteLater();

    if (clickedButton == serverButton)
    {
        Server *server = new Server(this);
        network_ = server;
        connect(server, SIGNAL(connected()), this, SLOT(connected()));
        connect(server, SIGNAL(disconnected()), this, SLOT(disconnected()));

        if (!server->init())
        {
            return false;
        }

        setWindowTitle("Server");
        QString message = "\t\tPort: " + server->getPort();
        statusBar()->showMessage(message);
    }
    else if (clickedButton == clientButton)
    {
        Client *client = new Client(this);
        connect(client, SIGNAL(disconnected()), this, SLOT(disconnected()));
        network_ = client;
        ConnectServerDialog *dialog = new ConnectServerDialog(client);

        if (!dialog->exec())
        {
            return false;
        }
        setWindowTitle("Client");
        connected();
    }
    else
    {
        return false;
    }

    return true;
}

void CannonGameMainWindow::connected()
{
    GameClass *game = new GameClass(this);
    connect(game, SIGNAL(gameOver(QString)), this, SLOT(gameOver(QString)));

    QGraphicsView *graphicsView = new QGraphicsView;
    setCentralWidget(graphicsView);
    graphicsView->setFixedSize(800, 600);
    game->startGame(graphicsView, network_);
}

void CannonGameMainWindow::disconnected()
{
    QMessageBox::information(this, tr("Bad news"), tr("Disconnected"));
    close();
}

void CannonGameMainWindow::gameOver(const QString &string)
{
    disconnect(network_, SIGNAL(disconnected()), this, SLOT(disconnected()));
    QMessageBox::information(this, tr("Game over"), string);
    close();
}
