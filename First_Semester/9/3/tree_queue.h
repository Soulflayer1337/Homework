#pragma once
#include <iostream>
#include "Pair.h"

struct TreeQueue;

TreeQueue *createTree();
void deleteTree(TreeQueue *tree);

void push(TreeQueue *tree, Pair<int, int> *value);
Pair<int, int> *pop(TreeQueue *tree);
void removeElement(TreeQueue *tree, Pair<int, int> *value);
bool isEmpty(TreeQueue *tree);
void printQueue(TreeQueue *tree);
