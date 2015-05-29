#ifndef TICTACTOEWIDGET_H
#define TICTACTOEWIDGET_H

#include <QWidget>
#include <QPushButton>
#include <QGridLayout>
#include <QSignalMapper>
#include "tictactoe.h"

namespace Ui {
class TicTacToeWidget;
}

class TicTacToeWidget : public QWidget
{
    Q_OBJECT

public:
    explicit TicTacToeWidget(QWidget *parent = 0);
    ~TicTacToeWidget();

public slots:
    void spotClicked(const int index);
    void optionClicked(const int index);

private:
    void rebuild();

    Ui::TicTacToeWidget *ui;
    QSignalMapper *spotsSignalMapper;
    QSignalMapper *optionsSignalMapper;
    QGridLayout *gridLayout;
    QPushButton *buttons;
    QPushButton *optionButtons;
    unsigned int *currentSettings;
    TicTacToe *game;
};

#endif // TICTACTOEWIDGET_H
