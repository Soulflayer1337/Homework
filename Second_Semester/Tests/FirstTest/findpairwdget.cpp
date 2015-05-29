#include "findpairwdget.h"
#include "ui_findpairwdget.h"
#include <QMessageBox>

FindPairWdget::FindPairWdget(QWidget *parent) :
    QWidget(parent),
    size(2),
    lastIndex(0),
    prelastIndex(-1),
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
    findPair = new FindPair(size);

    for (unsigned int i = 0; i < size; i++)
        for (unsigned int j = 0; j < size; j++)
        {
            int index = i * size + j;
            buttons[index].setText("");
            buttons[index].setSizeIncrement(20, 20);
            connect(&buttons[index], SIGNAL(clicked()), signalMapper, SLOT(map()));
            signalMapper->setMapping(&buttons[index], index);
            gridLayout->addWidget(&buttons[index], i, j);
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

    delete ui;
}

void FindPairWdget::clicked(const int index)
{

    if (lastIndex == -1)
    {
        buttons[index].setText(QString::number(findPair->numberIn(index / size, index % size)));

        lastIndex = index;

        short res = (findPair->check(prelastIndex / size, prelastIndex % size, index / size, index % size));

        if (res == 0)
            buttons[prelastIndex].setEnabled(true);
        else
        {
            buttons[index].setEnabled(false);

            if (res == 2)
                QMessageBox::information(this, "You've won!", "You've won!", QMessageBox::Ok);
        }
    }
    else
    {
        if (prelastIndex != -1 && buttons[prelastIndex].isEnabled())
        {
            buttons[prelastIndex].setText("");
            buttons[lastIndex].setText("");
        }
        lastIndex = -1;

        prelastIndex = index;
        buttons[index].setEnabled(false);
        buttons[index].setText(QString::number(findPair->numberIn(index / size, index % size)));
    }

}
