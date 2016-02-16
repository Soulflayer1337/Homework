#pragma once

#include <QDialog>

class Client;
class QLineEdit;

class ConnectServerDialog : public QDialog
{
    Q_OBJECT
public:
    explicit ConnectServerDialog(Client *client);
    ~ConnectServerDialog() Q_DECL_OVERRIDE;

private slots:
    void tryToConnect();

private:
    QLineEdit *portLineEdit_;

    Client *client_;
};
