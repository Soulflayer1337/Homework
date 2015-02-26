#pragma once

class Stack
{
public:
    void virtual push(int value) = 0;
    int virtual pop() = 0;
    int virtual top() = 0;
    bool virtual isEmpty() const = 0;
    virtual ~Stack() {}
};
