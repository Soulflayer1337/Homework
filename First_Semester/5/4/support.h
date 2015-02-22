#pragma once
//This header allows to work with C-strings

void moreMem(char **string, int &size);
bool isTheSame(char *first, char *second);
char *readUntil(char lastSymbol, FILE *file = nullptr);
