#pragma once

#include "inumbergenerator.h"
#include <QQueue>

class FakeNumberGenerator : public INumberGenerator
{
public:
    FakeNumberGenerator();
    int getNumber() override;
    void addNumberToQueue(int number);
    void clearQueue();

private:
    QQueue<int> numbers;
};
