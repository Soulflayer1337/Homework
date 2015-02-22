#pragma once
#include <iostream>

struct ArithmeticTree;

ArithmeticTree *createArithmeticTree();
void deleteArithmeticTree(ArithmeticTree *tree);

void buildTree(ArithmeticTree *tree, std::istream &stream = std::cin);
void printTree(ArithmeticTree *tree, std::ostream &stream = std::cout);
int countAsnwer(ArithmeticTree *tree);
