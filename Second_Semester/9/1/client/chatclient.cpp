#include "chatclient.h"
#include "ui_chatclient.h"

ChatClient::ChatClient(QWidget *parent) :
    QWidget(parent),
    chatText(new QTextEdit),
    portLineEdit(new QLineEdit),
    connectionButton(new QPushButton("Connect")),
    newMessageEdit(new QLineEdit),
    sendButton(new QPushButton("Send")),
    portLabel(new QLabel("Server port: ")),
    tcpSocket(new QTcpSocket(this)),
    networkSession(nullptr),
    blockSize(0),
    ui(new Ui::ChatClient)
{
    QGridLayout *windowLayout = new QGridLayout;
    windowLayout->addWidget(portLabel, 0, 0);
    windowLayout->addWidget(portLineEdit, 0, 1, 1, 3);
    windowLayout->addWidget(connectionButton, 0, 4);
    windowLayout->addWidget(chatText, 1, 0, 4, 4);
    windowLayout->addWidget(newMessageEdit, 5, 0, 1, 3);
    windowLayout->addWidget(sendButton, 5, 3);

    setLayout(windowLayout);
    setWindowTitle("Chat client");
    setFixedSize(400, 300);

    portLineEdit->setValidator(new QIntValidator(1, 65535, this));
    portLineEdit->setFocus();
    connectionButton->setEnabled(false);
    makeSendButtonEnabled();
    chatText->setReadOnly(true);

    connect(newMessageEdit, SIGNAL(returnPressed()), sendButton, SLOT(click()));
    connect(newMessageEdit, SIGNAL(textChanged(QString)), this, SLOT(makeSendButtonEnabled()));
    connect(portLineEdit, SIGNAL(returnPressed()), connectionButton, SLOT(click()));
    connect(portLineEdit, SIGNAL(textChanged(QString)), this, SLOT(makeConnectButtonEnabled()));

    QNetworkConfigurationManager manager;

    if (manager.capabilities() & QNetworkConfigurationManager::NetworkSessionRequired)
    {
        networkSession = new QNetworkSession(manager.defaultConfiguration(), this);
        connect(networkSession, SIGNAL(opened()), this, SLOT(makeConnectButtonEnabled()));
        networkSession->open();
    }

    connect(tcpSocket, SIGNAL(error(QAbstractSocket::SocketError)), this, SLOT(displayError(QAbstractSocket::SocketError)));
    connect(tcpSocket, SIGNAL(readyRead()), this, SLOT(incomingData()));
    connect(tcpSocket, SIGNAL(connected()), this, SLOT(sessionOpened()));
    connect(tcpSocket, SIGNAL(disconnected()), this, SLOT(disconnected()));
    connect(connectionButton, SIGNAL(clicked()), this, SLOT(connectToServer()));
    connect(sendButton, SIGNAL(clicked()), this, SLOT(sendMessage()));

    ui->setupUi(this);
}

ChatClient::~ChatClient()
{
    delete ui;
}

void ChatClient::connectToServer()
{
    tcpSocket->abort();
    tcpSocket->connectToHost("localhost", portLineEdit->text().toInt());
    makeConnectButtonEnabled();
}

void ChatClient::makeConnectButtonEnabled()
{
    connectionButton->setEnabled((!networkSession || networkSession->isOpen()) &&
                                 (tcpSocket->state() == QAbstractSocket::ConnectedState ||
                                  tcpSocket->state() == QAbstractSocket::UnconnectedState) &&
                                 !portLineEdit->text().isEmpty());
}

void ChatClient::makeSendButtonEnabled()
{
    sendButton->setEnabled(tcpSocket && tcpSocket->state() == QAbstractSocket::ConnectedState && !newMessageEdit->text().isEmpty());
}

void ChatClient::incomingData()
{
    QDataStream in(tcpSocket);
    if (blockSize == 0)
    {
        if (tcpSocket->bytesAvailable() < (int)sizeof(quint16))
            return;
        in >> blockSize;
    }
    if (tcpSocket->bytesAvailable() >= blockSize)
    {
        QString message;
        in >> message;
        chatText->append("Server: " + message);
        blockSize = 0;
    }
}

void ChatClient::sendMessage()
{
    QByteArray block;
    QDataStream out(&block, QIODevice::WriteOnly);
    out << (quint16)0;
    out << newMessageEdit->text();
    out.device()->seek(0);
    out << (quint16)(block.size() - sizeof(quint16));
    tcpSocket->write(block);

    chatText->append("Me: " + newMessageEdit->text());
    newMessageEdit->clear();
    newMessageEdit->setFocus();
}

void ChatClient::sessionOpened()
{
    makeSendButtonEnabled();
    newMessageEdit->setFocus();
    chatText->append("Connected.");
}

void ChatClient::disconnected()
{
    chatText->append("Disconnected.");
    makeSendButtonEnabled();
}

void ChatClient::displayError(QAbstractSocket::SocketError socketError)
{
    switch (socketError)
    {
    case QAbstractSocket::RemoteHostClosedError:
        break;
    case QAbstractSocket::ConnectionRefusedError:
    {
        QMessageBox::information(this, "Chat client", "The connection was refused.");
        break;
    }
    default:
        QMessageBox::information(this, "Chat client", tr("The following error ocurred: %1").arg(tcpSocket->errorString()));
    }
    makeConnectButtonEnabled();
}
