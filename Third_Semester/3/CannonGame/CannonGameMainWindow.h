#pragma once

#include <QMainWindow>

class Network;

class CannonGameMainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit CannonGameMainWindow(QWidget *parent = 0);

    bool initNetwork();

private slots:
    void connected();
    void disconnected();
    void gameOver(const QString &string);

private:
    Network *network_;
};
