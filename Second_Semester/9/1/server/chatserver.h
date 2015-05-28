#ifndef CHATSERVER_H
#define CHATSERVER_H

#include <QWidget>
#include <QtWidgets>
#include <QtNetwork>

namespace Ui {
class ChatServer;
}

class ChatServer : public QWidget
{
    Q_OBJECT

public:
    explicit ChatServer(QWidget *parent = 0);
    ~ChatServer();

private slots:
    void sessionOpened();
    void connectClient();
    void sendMessage();
    void disconnected();
    void makeButtonEnabled();
    void incomingData();

private:
    QTextEdit *chatText;
    QLineEdit *newMessageEdit;
    QPushButton *sendButton;
    QLabel *portLabel;

    QTcpServer *tcpServer;
    QTcpSocket *tcpSocket;
    QNetworkSession *networkSession;
    quint16 blockSize;

    Ui::ChatServer *ui;
};

#endif // CHATSERVER_H
