#pragma once

#include <cstdio>
#include "list.h"
#include "support.h"

struct Contact
{
    char *name;
    char *number;
};

typedef List<Contact> *Handbook;

void deleteContact(Contact obj);
bool printName(Contact element, Contact example);
bool printNumber(Contact element, Contact example);
void readFromFile(FILE *file, Handbook handbook);
void writeContact(Contact element, FILE *file);
Contact readFromConsole();
void saveToFile(FILE *file, Handbook handbook);
