#include "calcwindow.h"
#include "ui_calcwindow.h"
#include <QStringList>
#include <QMessageBox>

CalcWindow::CalcWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CalcWindow)
{
    ui->setupUi(this);

    numberMapper = new QSignalMapper(this);
    signMapper = new QSignalMapper(this);

    gridLayout = new QGridLayout;
    calculator = new Calculator;

    QFont font;
    font.setPixelSize(19);
    font.setStyleName("Arial Black");

    lineEdit = new QLineEdit;
    lineEdit->setFixedHeight(30);
    lineEdit->setAlignment(Qt::AlignRight);
    lineEdit->setEnabled(false);
    lineEdit->setFont(font);
    lineEdit->setText("0");

    gridLayout->addWidget(lineEdit, 0, 0, 1, 4);

    QStringList buttonsName;

    buttonsName << "1" << "2" << "3" << "+"
                << "4" << "5" << "6" << "-"
                << "7" << "8" << "9" << "*"
                << "0" << "." << "=" << "/";

    buttons = new QPushButton[16];

    for (int i = 0; i < 16; i++)
    {
        buttons[i].setText(buttonsName[i]);
        buttons[i].setFixedSize(40, 40);
        buttons[i].setFont(font);

        if (i % 4 != 3 && i != 14)
        {
            connect(&buttons[i], SIGNAL(clicked()), numberMapper, SLOT(map()));
            numberMapper->setMapping(&buttons[i], buttonsName[i]);
        }
        else
        {
            connect(&buttons[i], SIGNAL(clicked()), signMapper, SLOT(map()));
            signMapper->setMapping(&buttons[i], buttonsName[i]);
        }
        gridLayout->addWidget(&buttons[i], i / 4 + 1, i % 4);
    }

    connect(numberMapper, SIGNAL(mapped(QString)), this, SLOT(numberClicked(QString)));
    connect(signMapper, SIGNAL(mapped(QString)), this, SLOT(signClicked(QString)));

    setLayout(gridLayout);

    status = 2;
}

CalcWindow::~CalcWindow()
{
    delete ui;
}

void CalcWindow::numberClicked(QString buttonName)
{
    if (status)
    {
        status = 0;
        lineEdit->setText("0");
    }

    if (lineEdit->text().length() == 1 && lineEdit->text() == "0" && buttonName != ".")
        lineEdit->setText(buttonName);
    else
        lineEdit->setText(lineEdit->text() + buttonName);
}

void CalcWindow::signClicked(QString buttonName)
{
    if (status == 1)
    {
        QMessageBox::warning(this, "Warning!", "You should enter the number first!", QMessageBox::Critical, 0);
        return;
    }

    try
    {
        lineEdit->setText(QString::number(calculator->count(lineEdit->text().toDouble(), buttonName[0].toLatin1())));
        status = 1 + (buttonName[0].toLatin1() == '=');
    }
    catch (DividedByZero)
    {
        QMessageBox::warning(this, "Great!", "Oops, you just divi~", QMessageBox::Critical, 0);
    }
}
