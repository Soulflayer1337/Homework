#include "bst.h"

void printHelp()
{
    printf("\n\n****************************************************************\n");
    printf("Type:\n'1' - to add new value.\n'2' - to remove value.\n'3' - to check if the value exists.\n");
    printf("'4' - to print tree elements in ascending order.\n'5' - to print tree elements in descending order.\n");
    printf("'6' - to print tree elements using the following format (a b c).\n");
    printf("'7' - to print the list of commands.");
    printf("\n****************************************************************\n\n");
}

void dialog(BinarySearchTree<int> *tree)
{
    enum command_list {_exit = 0,_add, _remove, _exists, _printUp, _printDown, _printDebug, _help};
    command_list command = _help;

    do
    {
        command = _help;
        printf("Enter command: ");
        scanf("%d", &command);

        switch (command)
        {
            case _add:
            {
                printf("Enter the value you want to add: ");
                int value = 0;
                scanf("%d", &value);
                addElement(tree, value);
                break;
            }
            case _remove:
            {
                printf("Enter the value you wnat to remove: ");
                int value = 0;
                scanf("%d", &value);
                removeElement(tree, value);
                break;
            }
            case _exists:
            {
                printf("Enter the value you want to check: ");
                int value = 0;
                scanf("%d", &value);
                printf((exists(tree, value) ? "%d exists.\n" : "%d doesn't exist.\n"), value);
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
                printf("Goodbye. I hope, everything was fine.\n");
                break;
            }
            default:
            {
                printf("Never seen this strange command.\nIt is used in another program, isn't it?\n");
                break;
            }
        }
        printf("\n\n");
    }
    while (command != _exit);
}

int main()
{
    printf("Welcome to this program. Type '7' to see the list of available commands!\n");
    BinarySearchTree<int> *tree = createTree<int>();
    dialog(tree);
    deleteTree(tree);
    return 0;
}
