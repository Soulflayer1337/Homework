#pragma once

bool isNumber(char symb);
bool isOpened(char symb);
bool isClosed(char symb);
bool firstPriority(char symb);
bool secondPriority(char symb);
bool isOperation(char symb);

int newValue(char symb, int left, int right);
int charToInt(char symb);
