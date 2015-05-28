#include "tictactoewidget.h"
#include "ui_tictactoewidget.h"
#include <QMessageBox>
#include <QInputDialog>
#include <QFont>

TicTacToeWidget::TicTacToeWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TicTacToeWidget),
    spotsSignalMapper(nullptr),
    optionsSignalMapper(nullptr),
    gridLayout(nullptr),
    buttons(nullptr),
    optionButtons(new QPushButton[3]),
    currentSettings(new unsigned int[3]),
    game(nullptr)
{
    ui->setupUi(this);

    optionsSignalMapper = new QSignalMapper(this);

    QFont font;
    font.setPixelSize(20);
    font.setBold(true);
    font.setStyleName("Arial");


    for (int i = 0; i < 3; i++)
    {
        currentSettings[i] = 3;
        optionButtons[i].setSizeIncrement(50, 50);
        optionButtons[i].setFont(font);
        connect(&optionButtons[i], SIGNAL(clicked()), optionsSignalMapper, SLOT(map()));
        optionsSignalMapper->setMapping(&optionButtons[i], i);
    }

    optionButtons[0].setText("H");
    optionButtons[0].setToolTip("Number of rows");
    optionButtons[1].setText("W");
    optionButtons[1].setToolTip("Number of columns");
    optionButtons[2].setText("R");
    optionButtons[2].setToolTip("Number in the row");

    connect(optionsSignalMapper, SIGNAL(mapped(int)), this, SLOT(optionClicked(int)));

    rebuild();
}

TicTacToeWidget::~TicTacToeWidget()
{
    delete gridLayout;
    delete spotsSignalMapper;
    delete optionsSignalMapper;
    delete[] buttons;
    delete[] optionButtons;
    delete[] currentSettings;
    delete game;
    delete ui;
}

void TicTacToeWidget::spotClicked(const int index)
{
    unsigned int row = index / currentSettings[1];
    unsigned int column = index % currentSettings[1];

    if (game->marked(row, column) || game->getWinner() != empty)
        return;

    game->markTheSpot(row, column);
    buttons[index].setText(game->markInTheCell(row, column) == cross ? "X" : "O");

    if (game->getWinner() != empty)
    {
        QString text = "";

        if (game->getWinner() == cross)
            text = "First player won!";
        else if (game->getWinner() == naught)
            text = "Second player won!";
        else
            text = "Draw!";

        QMessageBox::information(this, "Game is over", text, QMessageBox::Ok);
    }
}

void TicTacToeWidget::optionClicked(const int index)
{
    bool isOk = false;
    QString option = "";
    int maxValue = 20;

    if (index == 2)
    {
        option = "Number in the row:";
        maxValue = (currentSettings[0] < currentSettings[1] ? currentSettings[0] : currentSettings[1]);
    }
    else
        option = (index ? "Number of rows:" : "Number of columns:");

    int newAmount = QInputDialog::getInt(this, "Set new value.", option, currentSettings[index], 3, maxValue, 1, &isOk);

    if (isOk)
    {
        currentSettings[index] = newAmount;
        rebuild();
    }
}

void TicTacToeWidget::rebuild()
{
    if (spotsSignalMapper)
    {
        delete gridLayout;
        delete spotsSignalMapper;
        delete[] buttons;
        delete game;
    }

    game = new TicTacToe(currentSettings[0], currentSettings[1], currentSettings[2]);
    gridLayout = new QGridLayout;
    spotsSignalMapper = new QSignalMapper(this);
    buttons = new QPushButton[currentSettings[0] * currentSettings[1]];

    QFont font;
    font.setPixelSize(25);
    font.setBold(true);
    font.setStyleName("Arial");

    gridLayout->addWidget(&optionButtons[0], 0, currentSettings[1] - 3);
    gridLayout->addWidget(&optionButtons[1], 0, currentSettings[1] - 2);
    gridLayout->addWidget(&optionButtons[2], 0, currentSettings[1] - 1);

    for (unsigned int i = 0; i < currentSettings[0]; i++)
        for (unsigned int j = 0; j < currentSettings[1]; j++)
        {
            int index = i * currentSettings[1] + j;
            buttons[index].setFont(font);
            buttons[index].setText("");
            connect(&buttons[index], SIGNAL(clicked()), spotsSignalMapper, SLOT(map()));
            spotsSignalMapper->setMapping(&buttons[index], index);
            gridLayout->addWidget(&buttons[index], i + 1, j);
        }

    connect(spotsSignalMapper, SIGNAL(mapped(int)), this, SLOT(spotClicked(int)));

    setFixedSize(currentSettings[1] * 42, (currentSettings[0] + 1) * 42);
    setLayout(gridLayout);
}
