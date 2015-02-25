#include <iostream>
#include "doublelinkedlist.h"
#include "sortedlist.h"

using std::cin;
using std::cout;

void console()
{
    List *DLList = new DoubleLinkedList();
    List *SList = new SortedList();

    while (true)
    {
        std::string command = "help";
        std::cin >> command;

        if (command == "help")
            std::cout << "'add X' - to add X in list.\n'remove X' - to remove X from the list.\n"
                      << "'removeAll' - to remove all X from the list\n'exists X' - to know if there is an 'X' in the list\n"
                      << "'empty' - to learn whether the list is empty\n'print' - to print out the list\n'exit' - to exit\n";
        else if (command == "add")
        {
            int value = 0;
            cin >> value;
            DLList->add(value);
            SList->add(value);
        }
        else if (command == "remove")
        {
            int value = 0;
            cin >> value;
            DLList->remove(value);
            SList->remove(value);
        }
        else if (command == "removeAll")
        {
            int value = 0;
            cin >> value;
            DLList->removeAll(value);
            SList->removeAll(value);
        }
        else if (command == "exists")
        {
            int value = 0;
            cin >> value;
            std::cout << "DoubleLinkedList " << (DLList->exists(value) ? "contains " : "doesn't contain ") << value
                      << "\nSortedList " << (SList->exists(value) ? "contains " : "doesn't contain ") << value << std::endl;
        }
        else if (command == "empty")
            cout << "DoubleLinkedList " << (DLList->isEmpty() ? "is" : "isn't") << " empty.\nSortedList " << (SList->isEmpty() ? "is" : "isn't") << " empty.\n";
        else if (command == "print")
        {
            cout << "DoubleLinkedList contains: ";
            DLList->print();
            cout << "SortedList contains: ";
            SList->print();
        }
        else if (command == "exit")
            break;
        else
            cout << "Unknown command!\n";
    }

    delete DLList;
    delete SList;
}

int main()
{
    cout << "Enter 'help' to see a list of commands:\n";
    console();
    return 0;
}
