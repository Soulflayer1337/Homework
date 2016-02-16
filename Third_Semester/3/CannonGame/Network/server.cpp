#include "server.h"

#include <QNetworkConfigurationManager>
#include <QNetworkSession>
#include <QTcpServer>
#include <QTcpSocket>

#include "GameObjects/landscape.h"
#include "util.h"

Server::Server(QObject *parent) :
    Network(parent),
    tcpServer_(nullptr)
{
}

bool Server::init()
{
    QNetworkConfigurationManager manager;

    if (manager.capabilities() & QNetworkConfigurationManager::NetworkSessionRequired)
    {
        networkSession_ = new QNetworkSession(manager.defaultConfiguration(), this);
        connect(networkSession_, SIGNAL(opened()), this, SLOT(sessionOpened()));
        networkSession_->open();
    }
    else
    {
        sessionOpened();
    }

    if (!tcpServer_)
    {
        return false;
    }

    connect(tcpServer_, SIGNAL(newConnection()), this, SLOT(connectClient()));
    return true;
}

QString Server::getPort() const
{
    if (tcpServer_ && tcpServer_->isListening())
    {
        return QString::number(tcpServer_->serverPort());
    }
    else
    {
        return QString();
    }
}

void Server::sendLandscape(Landscape *landscape)
{
    QVector<int> field = landscape->getField();
    int width = landscape->getWidth();
    QString message = "L";
    message += QString::number(width) + " " + QString::number(landscape->getHeight());

    for (int i = 0; i < width; i++)
    {
        message += " " + QString::number(field[i]);
    }

    sendMessage(message);
    return;
}

void Server::sessionOpened()
{
    tcpServer_ = new QTcpServer(this);

    if (!tcpServer_->listen())
    {
        qSafeDelete(tcpServer_);
    }
    else
    {
        tcpServer_->setMaxPendingConnections(1);
    }
}

void Server::connectClient()
{
    if (!(tcpSocket_ && tcpSocket_->state() != QAbstractSocket::UnconnectedState))
    {
        tcpSocket_ = tcpServer_->nextPendingConnection();
        connect(tcpSocket_, SIGNAL(readyRead()), this, SLOT(newMessage()));
        connect(tcpSocket_, SIGNAL(disconnected()), this, SIGNAL(disconnected()));
        emit connected();
    }
}
