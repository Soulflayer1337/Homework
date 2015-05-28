#include "chatserver.h"
#include "ui_chatserver.h"

ChatServer::ChatServer(QWidget *parent) :
    QWidget(parent),
    chatText(new QTextEdit),
    newMessageEdit(new QLineEdit),
    sendButton(new QPushButton),
    portLabel(new QLabel),
    tcpServer(nullptr),
    tcpSocket(nullptr),
    networkSession(nullptr),
    blockSize(0),
    ui(new Ui::ChatServer)
{
    QGridLayout *windowLayout = new QGridLayout;
    windowLayout->addWidget(portLabel, 0, 0);
    windowLayout->addWidget(chatText, 1, 0, 4, 4);
    windowLayout->addWidget(newMessageEdit, 5, 0, 1, 3);
    windowLayout->addWidget(sendButton, 5, 3);

    setLayout(windowLayout);
    setWindowTitle("Chat server");
    setFixedSize(400, 300);

    makeButtonEnabled();
    chatText->setReadOnly(true);
    connect(newMessageEdit, SIGNAL(returnPressed()), sendButton, SLOT(click()));
    connect(sendButton, SIGNAL(clicked()), this, SLOT(sendMessage()));
    connect(newMessageEdit, SIGNAL(textChanged(QString)), this, SLOT(makeButtonEnabled()));

    QNetworkConfigurationManager manager;

    if (manager.capabilities() & QNetworkConfigurationManager::NetworkSessionRequired)
    {
        networkSession = new QNetworkSession(manager.defaultConfiguration(), this);
        connect(networkSession, SIGNAL(opened()), this, SLOT(sessionOpened()));
        networkSession->open();
    }
    else
        sessionOpened();

    connect(tcpServer, SIGNAL(newConnection()), this, SLOT(connectClient()));

    ui->setupUi(this);
}

ChatServer::~ChatServer()
{
    delete ui;
}

void ChatServer::sessionOpened()
{
    tcpServer = new QTcpServer(this);

    if (!tcpServer)
    {
        QMessageBox::critical(this, "Chat server", tr("Div... I mean, unable to start server: %1").arg(tcpServer->errorString()));
        close();
    }
    else
    {
        tcpServer->setMaxPendingConnections(1);
        portLabel->setText(tr("Port: %1").arg(tcpServer->serverPort()));
    }
}

void ChatServer::connectClient()
{
    if (tcpSocket && tcpSocket->state() != QAbstractSocket::UnconnectedState)
        QMessageBox::information(this, "Chat server", "More than one connection not allowed.", QMessageBox::Ok);
    else
    {
        tcpSocket = tcpServer->nextPendingConnection();
        connect(tcpSocket, SIGNAL(readyRead()), this, SLOT(incomingData()));
        connect(tcpSocket, SIGNAL(disconnected()), this, SLOT(disconnected()));
        chatText->append("Connected!");
        makeButtonEnabled();
    }
}

void ChatServer::sendMessage()
{
    QByteArray block;
    QDataStream out(&block, QIODevice::ReadOnly);
    out << (quint16)0;
    out << newMessageEdit->text();
    out.device()->seek(0);
    out << (quint16)(block.size() - sizeof(quint16));
    tcpSocket->write(block);

    chatText->append("Me: " + newMessageEdit->text());
    newMessageEdit->clear();
}

void ChatServer::disconnected()
{
    chatText->append("Disconnected.");
    makeButtonEnabled();
}

void ChatServer::makeButtonEnabled()
{
    sendButton->setEnabled(tcpSocket && tcpSocket->state() == QAbstractSocket::UnconnectedState && !newMessageEdit->text().isEmpty());
}

void ChatServer::incomingData()
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
        chatText->append("Client: " + message);
        blockSize = 0;
    }
}
