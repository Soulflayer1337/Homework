#include "contact.h"

void printHelp()
{
    printf("Enter:\n'0' - to exit.\n'1' - to add new record.\n'2' - to print all contacts at console.\n\
'3' - to find number using name.\n'4' - to find name using number.\n'5' - to save data.\n'6' - for the list of the commands.\n");
}

void dialog(FILE *file, Handbook handbook)
{
    bool exit = false;
    enum commands {_exit, _add, _printList, _findNumber, _findName, _saveToFile, _help, _default};

    while (!exit)
    {
        printf("Enter command: ");
        int cmd = _default;
        scanf("%d", &cmd);

        {
            char c = '0';
            while (c != '\n')
                scanf("%c", &c);

        }

        switch (cmd)
        {
        case _exit:
        {
            exit = true;
            break;
        }
        case _add:
        {
            addElement(handbook, readFromConsole());
            break;
        }
        case _printList:
        {
            if (!isEmpty(handbook))
                printList(handbook, writeContact);
            else
                printf("Handbook is empty!\n");
            break;
        }
        case _findNumber:
        {
            printf("Enter name: ");
            Contact example;
            example.name = readUntil('\n');
            example.number = nullptr;
            if (!printFromList(handbook, example, printNumber))
                printf("There is no contact with such name.\n");
            delete[] example.name;
            break;
        }
        case _findName:
        {
            printf("Enter number: ");
            Contact example;
            example.name = nullptr;
            example.number = readUntil('\n');
            if (!printFromList(handbook, example, printName))
                printf("There is no contact with such number.\n");
            delete[] example.number;
            break;
        }
        case _saveToFile:
        {
            saveToFile(file, handbook);
            break;
        }
        case _help:
        {
            printHelp();
            break;
        }
        default:
        {
            printf("This command doesn't exist!\n");
            break;
        }
        }
        printf("\n\n");
    }
    printf("Goodbye.\n");
}

int main()
{
    printf("Welcome to Handbook. Enter '6' to see list of commands.\n");

    FILE *file = fopen("contacts.txt", "r");
    Handbook handbook = createList<Contact>();

    if (file != nullptr)
    {
        readFromFile(file, handbook);
        fclose(file);
    }

    dialog(file, handbook);

    deleteList(handbook, deleteContact);

    return 0;
}
