#include "avl_tree.h"

void printHelp()
{
    std::cout << "\n\n****************************************************************\n"
    << "Type:\n'1' - to add new value.\n'2' - to remove value.\n'3' - to check if the value exists.\n"
    << "'4' - to print tree elements in ascending order.\n'5' - to print tree elements in descending order.\n"
    << "'6' - to print tree elements using the following format (a b c).\n"
    << "'7' - to print the list of commands."
    << "\n****************************************************************\n\n";
}

void dialog(Tree<int> *tree)
{
    enum command_list {_exit = 0,_add, _remove, _exists, _printUp, _printDown, _printDebug, _help};
    int command = _help;

    do
    {
        command = _help;
        printf("Enter command: ");
        std::cin >> command;

        switch (command)
        {
            case _add:
            {
                std::cout << "Enter the value you want to add: ";
                int value = 0;
                std::cin >> value;
                addElement(tree, value);
                break;
            }
            case _remove:
            {
                std::cout << "Enter the value you wnat to remove: ";
                int value = 0;
                std::cin >> value;
                removeElement(tree, value);
                break;
            }
            case _exists:
            {
                std::cout << "Enter the value you want to check: ";
                int value = 0;
                std::cin >> value;
                std::cout << value << (exists(tree, value) ? "exists.\n" : "doesn't exist.\n");
                break;
            }
            case _printUp:
            {
                printAscending(tree);
                break;
            }
            case _printDown:
            {
                printDescending(tree);
                break;
            }
            case _printDebug:
            {
                printDebug(tree);
                break;
            }
            case _help:
            {
                printHelp();
                break;
            }
            case _exit:
            {
                std::cout << "Goodbye. I hope, everything was fine.\n";
                break;
            }
            default:
            {
                std::cout << "Never seen this strange command.\nIt is used in another program, isn't it?\n";
                break;
            }
        }
        std::cout << "\n\n";
    }
    while (command != _exit);
}

int main()
{
    std::cout << "Welcome to this program. Type '7' to see the list of available commands!\n";
    Tree<int> *tree = createTree<int>();
    dialog(tree);
    deleteTree(tree);
    return 0;
}
