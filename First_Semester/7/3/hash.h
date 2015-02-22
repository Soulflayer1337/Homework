#pragma once
#include "List.h"

typedef unsigned int uint;

struct hashTable;

hashTable *createHash(size_t size);
void deleteHash(hashTable *table);

void addElement(hashTable *table, MyString value);
void printStatus(hashTable *table);
