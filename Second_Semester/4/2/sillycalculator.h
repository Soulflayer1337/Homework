#ifndef SILLYCALCULATOR_H
#define SILLYCALCULATOR_H

#include <QWidget>

namespace Ui {
class SillyCalculator;
}

class SillyCalculator : public QWidget
{
    Q_OBJECT

public:
    explicit SillyCalculator(QWidget *parent = 0);
    ~SillyCalculator();

private slots:
    void count();

private:
    Ui::SillyCalculator *ui;
};

#endif // SILLYCALCULATOR_H
