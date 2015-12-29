#pragma once

#include "network.h"

class Landscape;

/**
 * \brief The Client class represents the Client
 */
class Client : public Network
{
    Q_OBJECT
public:
    explicit Client(QObject *parent = nullptr);

    void connectToServer(int port);

signals:
    /// \brief emitted when the Landscape received by the network.
    void gotLandscape(Landscape *landscape);

protected:
    void decodeMessage(const QString &message) Q_DECL_OVERRIDE;
};
