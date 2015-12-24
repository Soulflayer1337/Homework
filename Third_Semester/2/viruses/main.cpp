#include <QDateTime>

#include "computerfactorytest.h"
#include "networktest.h"

int main()
{
    qsrand(QDateTime::currentMSecsSinceEpoch());
    ComputerFactoryTest computerFactoryTest;
    QTest::qExec(&computerFactoryTest);
    NetworkTest networkTest;
    QTest::qExec(&networkTest);
    return 0;
}

