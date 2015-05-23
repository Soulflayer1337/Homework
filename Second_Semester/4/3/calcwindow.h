#ifndef CALCWINDOW_H
#define CALCWINDOW_H

#include <QWidget>
#include "calculator.h"
#include <QPushButton>
#include <QGridLayout>
#include <QSignalMapper>
#include <QLineEdit>

namespace Ui {
class CalcWindow;
}

class CalcWindow : public QWidget
{
    Q_OBJECT

public:
    explicit CalcWindow(QWidget *parent = 0);
    ~CalcWindow();

private slots:
    void numberClicked(QString buttonName);
    void signClicked(QString buttonName);

private:
    int status; // Used to control the input of the numbers

    QPushButton *buttons;
    QLineEdit *lineEdit;
    QGridLayout *gridLayout;
    QSignalMapper *numberMapper;
    QSignalMapper *signMapper;
    Calculator *calculator;
    Ui::CalcWindow *ui;
};

#endif // CALCWINDOW_H
