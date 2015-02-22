#pragma once
#include "MyString.h"

struct ListNode;
struct List;

List *createList();
void deleteList(List *list);

int addElement(MyString &value, List *list);

void printStatus(List *list);
size_t lengthOfList(List *list);
bool isEmpty(List *list);
