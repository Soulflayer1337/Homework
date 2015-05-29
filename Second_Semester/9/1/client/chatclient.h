#ifndef CHATCLIENT_H
#define CHATCLIENT_H

#include <QWidget>
#include <QtWidgets>
#include <QtNetwork>

namespace Ui {
class ChatClient;
}

class ChatClient : public QWidget
{
    Q_OBJECT

public:
    explicit ChatClient(QWidget *parent = 0);
    ~ChatClient();

private slots:
    void connectToServer();
    void makeConnectButtonEnabled();
    void makeSendButtonEnabled();
    void incomingData();
    void sendMessage();
    void sessionOpened();
    void disconnected();
    void displayError(QAbstractSocket::SocketError socketError);

private:
    QTextEdit *chatText;
    QLineEdit *portLineEdit;
    QPushButton *connectionButton;
    QLineEdit *newMessageEdit;
    QPushButton *sendButton;
    QLabel *portLabel;

    QTcpSocket *tcpSocket;
    QNetworkSession *networkSession;
    quint16 blockSize;
    Ui::ChatClient *ui;
};

#endif // CHATCLIENT_H
