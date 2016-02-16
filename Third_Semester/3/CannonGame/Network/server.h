#pragma once

#include "network.h"

class QTcpServer;
class Landscape;

/**
 * @brief The Server class is a representation of the Server
 */
class Server : public Network
{
    Q_OBJECT
public:
    explicit Server(QObject *parent = nullptr);
    bool init();

    QString getPort() const;
    void sendLandscape(Landscape *landscape);

private slots:
    void sessionOpened();
    void connectClient();

private:
    QTcpServer *tcpServer_;
};
