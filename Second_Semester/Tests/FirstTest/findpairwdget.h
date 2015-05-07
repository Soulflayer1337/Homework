#ifndef FINDPAIRWDGET_H
#define FINDPAIRWDGET_H

#include <QWidget>
#include <QPushButton>
#include <QSignalMapper>
#include <QGridLayout>
#include "findpair.h"

namespace Ui {
class FindPairWdget;
}

class FindPairWdget : public QWidget
{
    Q_OBJECT

public:
    explicit FindPairWdget(QWidget *parent = 0);
    ~FindPairWdget();

public slots:
    void clicked(const int index);

private:
    unsigned int size;
    int lastIndex;
    int prelastIndex;
    QPushButton *buttons;
    QGridLayout *gridLayout;
    QSignalMapper *signalMapper;
    FindPair *findPair;
    Ui::FindPairWdget *ui;
};

#endif // FINDPAIRWDGET_H
