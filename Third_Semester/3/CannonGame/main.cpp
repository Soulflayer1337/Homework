#include "CannonGameWidget.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    CannonGameWidget w;
    w.show();

    return a.exec();
}
