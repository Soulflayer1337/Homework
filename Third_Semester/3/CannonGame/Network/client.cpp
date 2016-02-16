#include "client.h"

#include <QNetworkConfigurationManager>
#include <QNetworkSession>
#include <QTcpSocket>
#include <QVector>

#include "GameObjects/landscape.h"

Client::Client(QObject *parent) :
    Network(parent)
{
    tcpSocket_ = new QTcpSocket(this);
    QNetworkConfigurationManager manager;

    if (manager.capabilities() & QNetworkConfigurationManager::NetworkSessionRequired)
    {
        networkSession_ = new QNetworkSession(manager.defaultConfiguration(), this);
        networkSession_->opened();
    }

    connect(tcpSocket_, SIGNAL(readyRead()), this, SLOT(newMessage()));
    connect(tcpSocket_, SIGNAL(connected()), this, SIGNAL(connected()));
    connect(tcpSocket_, SIGNAL(disconnected()), this, SIGNAL(disconnected()));
}

void Client::connectToServer(int port)
{
    tcpSocket_->abort();
    tcpSocket_->connectToHost("localhost", port);
}

void Client::decodeMessage(const QString &message)
{
    if (!message.size())
    {
        return;
    }

    if (message.at(0) == QChar('L'))
    {
        Landscape *landscape = new Landscape;

        QStringList stringList = message.split(" ");

        stringList.first().remove(0, 1);
        int width = stringList.first().toInt();
        landscape->setHeight(stringList.at(1).toInt());

        QVector<int> vector;
        for (int i = 0; i < width; i++)
        {
            vector.push_back(stringList.at(2 + i).toInt());
        }

        landscape->setField(vector);
        emit gotLandscape(landscape);
    }
    else
    {
        Network::decodeMessage(message);
    }
}
