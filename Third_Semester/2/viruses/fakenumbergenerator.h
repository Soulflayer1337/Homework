#pragma once

#include "inumbergenerator.h"
#include <QQueue>

/// \brief The FakeNumberGenerator class is an implementation of INumberGenerator for tests
class FakeNumberGenerator : public INumberGenerator
{
public:
    FakeNumberGenerator();
    /// \brief takes first number from the queue.
    int getNumber() override;
    /// \brief adds number to the queue
    void addNumberToQueue(int number);
    /// \brief clears queue
    void clearQueue();

private:
    QQueue<int> numbers;
};
