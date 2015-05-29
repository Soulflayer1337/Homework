#include "findpairwdget.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    FindPairWdget w;
    w.show();

    return a.exec();
}
