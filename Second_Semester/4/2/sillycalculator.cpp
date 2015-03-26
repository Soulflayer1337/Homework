#include "sillycalculator.h"
#include "ui_sillycalculator.h"
#include <QMessageBox>

SillyCalculator::SillyCalculator(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SillyCalculator)
{
    ui->setupUi(this);
    connect(ui->firstNumber, SIGNAL(valueChanged(int)), this, SLOT(count())) ;
    connect(ui->secondNumber, SIGNAL(valueChanged(int)), this, SLOT(count()));
    connect(ui->sign, SIGNAL(currentIndexChanged(int)), this, SLOT(count()));
}

SillyCalculator::~SillyCalculator()
{
    delete ui;
}

void SillyCalculator::count()
{
    int leftOperand = ui->firstNumber->value();
    int rightOperand = ui->secondNumber->value();
    int sign = ui->sign->currentIndex();

    if (sign == 3 && rightOperand == 0)
    {
        QMessageBox *errorBox = new QMessageBox;
        errorBox->setText("It's dangerous to go alone! Take this!\n\"Divider by zero\" was obtained!");
        errorBox->exec();
        delete errorBox;
        return;
    }

    int ans = 0;

    switch (sign)
    {
    case 0:
    {
        ans = leftOperand + rightOperand;
        break;
    }
    case 1:
    {
        ans = leftOperand - rightOperand;
        break;
    }
    case 2:
    {
        ans = leftOperand * rightOperand;
        break;
    }
    case 3:
    {
        ans = leftOperand / rightOperand;
        break;
    }
    }

    ui->answer->setText(QString::number(ans));
}
