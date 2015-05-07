#include "findpairwdget.h"
#include "ui_findpairwdget.h"
#include <QMessageBox>

FindPairWdget::FindPairWdget(QWidget *parent) :
    QWidget(parent),
    size(6),
    pushedButton(nullptr),
    buttons(nullptr),
    gridLayout(nullptr),
    signalMapper(nullptr),
    findPair(nullptr),
    ui(new Ui::FindPairWdget)
{
    ui->setupUi(this);

    signalMapper = new QSignalMapper(this);
    gridLayout = new QGridLayout;
    buttons = new QPushButton[size * size];

    for (unsigned int i = 0; i < size; i++)
        for (unsigned int j = 0; j < size; j++)
        {
            int index = i * size + j;
            pushedButton = &buttons[index];
            buttons[index].setText("");
            buttons[index].setSizeIncrement(20, 20);
            connect(&buttons[index], SIGNAL(clicked()), signalMapper, SLOT(map()));
            signalMapper->setMapping(&buttons[index], index);
            gridLayout->addWidget(&buttons[index], i % size, j % size);
        }

    if (size % 2)
        buttons[(size * size) / 2].setEnabled(false);

    connect (signalMapper, SIGNAL(mapped(int)), this, SLOT(clicked(int)));

    setLayout(gridLayout);
}

FindPairWdget::~FindPairWdget()
{
    delete buttons;
    delete gridLayout;
    delete signalMapper;
    delete findPair;
    delete optionsButton;

    delete ui;
}

void FindPairWdget::clicked(const int index)
{
    buttons[index].setText(QString::number(findPair->numberIn(index / size, index % size)));

    if (pushedButton)
    {
        int indexFirst = 0;

        while (pushedButton == &buttons[indexFirst])
            indexFirst++;

        short res = (findPair->check(indexFirst / size, indexFirst % size, index / size, index % size));

        if (res == 0)
        {
            pushedButton->setText("");
            buttons[index].setText("");
            pushedButton->setEnabled(true);
        }
        else
        {
            buttons[index].setEnabled(false);

            if (res == 2)
                QMessageBox::information(this, "You've won!", "You've won!", QMessageBox::Ok);

        }

        pushedButton = nullptr;
    }
    else
    {
        pushedButton = &buttons[index];
        buttons[index].setEnabled(false);
    }
}
