#include "calcwindow.h"
#include <QApplication>
#include "calculatortest.h"

int main(int argc, char *argv[])
{
    CalculatorTest calculatorTest;
    QTest::qExec(&calculatorTest);

    QApplication a(argc, argv);
    CalcWindow w;
    w.show();

    return a.exec();
}
