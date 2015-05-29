#include "tictactoewidget.h"
#include <QApplication>
#include "tictactoetest.h"

int main(int argc, char *argv[])
{
    TicTacToeTest ticTacToeTest;
    QTest::qExec(&ticTacToeTest);

    QApplication a(argc, argv);
    TicTacToeWidget w;
    w.show();

    return a.exec();
}
