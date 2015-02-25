#pragma once

class List
{
public:
    virtual ~List() {};
    void virtual add(int value) = 0;
    bool virtual remove(int value) = 0;
    void virtual removeAll(int value) = 0;
    bool virtual exists(int value) = 0;
    bool virtual isEmpty() = 0;
    void virtual print() = 0;
};
