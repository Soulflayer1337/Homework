#pragma once

#include "network.h"

class Landscape;

class Client : public Network
{
    Q_OBJECT
public:
    explicit Client(QObject *parent = nullptr);

    void connectToServer(int port);

signals:
    void gotLandscape(Landscape *landscape);

protected:
    void decodeMessage(const QString &message) Q_DECL_OVERRIDE;
};
