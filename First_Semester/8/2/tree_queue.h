#pragma once
#include <iostream>
#include "Pair.h"

struct TreeQueue;

TreeQueue *createTree();
void deleteTree(TreeQueue *tree);

void push(TreeQueue *tree, Pair<int, int> *value);
Pair<int, int> *pop(TreeQueue *tree);
bool isEmpty(TreeQueue *tree);
