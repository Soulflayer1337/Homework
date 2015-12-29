#pragma once

#include <QObject>

class Cannon;
class InputManager;
class NetworkInputManager;
class QTcpSocket;
class QNetworkSession;

class Network : public QObject
{
    Q_OBJECT
public:
    explicit Network(QObject *parent = 0);

    void observeInputManager(Cannon *subject);
    void initInputManager(Cannon *subject);

signals:
    void disconnected();
    void connected();

protected slots:
    void sendMessage(const QString &message);

private slots:
    void newMessage();

protected:
    virtual void decodeMessage(const QString &message);

    NetworkInputManager *inputManager_;
    QTcpSocket *tcpSocket_;
    QNetworkSession *networkSession_;
    quint16 blockSize_;
};
