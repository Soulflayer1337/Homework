#include "CannonGameMainWindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    CannonGameMainWindow w;

    if (!w.initNetwork())
    {
        return 0;
    }

    w.show();

    return a.exec();
}
