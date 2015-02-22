#include "Arithmetic_tree.h"

struct TreeNode
{
    bool isSymbol;
    int count;
    TreeNode *left;
    TreeNode *right;
};

struct ArithmeticTree
{
    TreeNode *root;
};

/*
 * Create new ArithmeticTree
 */
ArithmeticTree *createArithmeticTree()
{
    ArithmeticTree *tree = new ArithmeticTree;
    tree->root = nullptr;
    return tree;
}

/*
 * Delete or clear ArithmeticTree
 */
void deleteNode(TreeNode *node)
{
    if (node == nullptr)
        return;

    deleteNode(node->left);
    deleteNode(node->right);
    delete node;
}

void clearTree(ArithmeticTree *tree)
{
    deleteNode(tree->root);
    tree->root = nullptr;
}

void deleteArithmeticTree(ArithmeticTree *tree)
{
    deleteNode(tree->root);
    delete tree;
}

/*
 * Build ArithmeticTree
 */
TreeNode *createNode()
{
    TreeNode *node = new TreeNode;

    node->count = 0;
    node->isSymbol = 0;
    node->left = node->right = nullptr;

    return node;
}

void buildTree(TreeNode **node, std::istream &stream)
{
    (*node) = createNode();

    while (stream.peek() == ' ')
        stream.ignore();

    if (stream.peek() == '(')
    {
        stream.ignore();

        char symb = '\0';
        stream >> symb;
        (*node)->count = symb;
        (*node)->isSymbol = true;

        buildTree(&(*node)->left, stream);
        buildTree(&(*node)->right, stream);
        stream.ignore();
    }
    else
        stream >> (*node)->count;
}

void buildTree(ArithmeticTree *tree, std::istream &stream)
{
    if (tree->root != nullptr)
        clearTree(tree);

    buildTree(&tree->root, stream);
}

/*
 * Print expression
 */
void printNode(TreeNode *node, std::ostream &stream)
{
    if (node->isSymbol)
    {
        stream << "(";
        printNode(node->left, stream);
        stream << " " << (char)node->count << " ";
        printNode(node->right, stream);
        stream << ")";
    }
    else
        stream << node->count;
}

void printTree(ArithmeticTree *tree, std::ostream &stream)
{
    printNode(tree->root, stream);
}

/*
 * Print answer to expression
 */
int makeOperation(char _operator, int _left, int _right)
{
    int count = 0;

    switch(_operator)
    {
        case '-':
        {
            count = _left - _right;
            break;
        }
        case '+':
        {
            count = _left + _right;
            break;
        }
        case '*':
        {
            count = _left * _right;
            break;
        }
        case '/':
        {
            count = _left / _right; //Hope, nobody's going to divide something by zero.
            break;
        }
    }

    return count;
}

int countAnswer(TreeNode *node)
{
    int count = 0;

    if (node->isSymbol)
        count = makeOperation(node->count, countAnswer(node->left), countAnswer(node->right));
    else
        count = node->count;

    return count;
}

int countAsnwer(ArithmeticTree *tree)
{
    return countAnswer(tree->root);
}
