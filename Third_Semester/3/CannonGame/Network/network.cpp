#include "network.h"

#include <QDataStream>
#include <QTcpSocket>

#include "GameObjects/cannon.h"
#include "inputobserver.h"
#include "InputManager/networkinputmanager.h"

Network::Network(QObject *parent) :
    QObject(parent),

    inputManager_(nullptr),
    tcpSocket_(nullptr),
    networkSession_(nullptr),
    blockSize_(0)
{
}

void Network::observeInputManager(Cannon *subject)
{
    InputObserver *inputObserver = new InputObserver(this, subject);
    connect(inputObserver, SIGNAL(inputInvoked(QString)),
            this, SLOT(sendMessage(QString)));
}

void Network::initInputManager(Cannon *subject)
{
    inputManager_ = new NetworkInputManager(this, subject);
}

void Network::newMessage()
{
    QDataStream in(tcpSocket_);
    if (!blockSize_)
    {
        if  (tcpSocket_->bytesAvailable() < (int)sizeof(quint16))
        {
            return;
        }
        in >> blockSize_;
    }
    if (tcpSocket_->bytesAvailable() >= blockSize_)
    {
        QString message;
        in >> message;
        blockSize_ = 0;
        decodeMessage(message);
    }
}

void Network::decodeMessage(const QString &message)
{
    if (inputManager_ && (message.size() > 1) && (message.at(0) == QChar('K')))
    {
        inputManager_->networkInputInvoked(message);
    }
}

void Network::sendMessage(const QString &message)
{
    QByteArray block;
    QDataStream out(&block, QIODevice::WriteOnly);
    out << (quint16)0;
    out << message;
    out.device()->seek(0);
    out << (quint16)(block.size() - sizeof(quint16));
    tcpSocket_->write(block);
}
