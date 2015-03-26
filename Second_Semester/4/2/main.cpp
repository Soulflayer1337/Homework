#include "sillycalculator.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    SillyCalculator w;
    w.show();

    return a.exec();
}
