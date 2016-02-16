#pragma once

#include <QObject>

class Cannon;
class InputManager;
class NetworkInputManager;
class QTcpSocket;
class QNetworkSession;

/**
 * \brief The Network class is a base class for the Client and Server
 */
class Network : public QObject
{
    Q_OBJECT
public:
    explicit Network(QObject *parent = 0);

    /// \brief sets the InputObserver for a subject and its input
    void observeInputManager(Cannon *subject);
    /// \brief initalize NetworkInputManager instance that is connected with a subject
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
