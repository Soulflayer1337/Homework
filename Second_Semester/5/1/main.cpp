#include <iostream>
#include "hashtable.h"
#include "stringhash.h"
#include "jenkinshash.h"
// Tests
#include "listtest.h"
#include "hashtabletest.h"

enum DialogueOptions
{
    quit = 0,
    addition,
    removing,
    checking,
    statistics,
    changeHash,
    viewHelp,
    wrongCommand
};

void help()
{
    std::cout << "List of commands: \n"
              << "'1' - to add new element.\n"
              << "'2' - to remove an element.\n"
              << "'3' - to check if the element exists.\n"
              << "'4' - to view statistics.\n"
              << "'5' - to change hash function.\n"
              << "'6' - to view list of commands.\n"
              << "'0' - to quit the program.\n";
}

void dialogue(HashTable *table)
{
    std::cout << "Type '6' to view the list of commands.\n";

    DialogueOptions option = viewHelp;

    do
    {
        std::cout << "Enter the command: ";

        unsigned int choise = 0;
        std::cin >> choise;

        if (choise < 7)
            option = DialogueOptions(choise);
        else
            option = wrongCommand;

        switch (option)
        {
        case addition:
        {
            std::cout << "Enter the string u want to add: ";
            std::string newString = "";
            std::cin >> newString;
            table->add(newString);
            break;
        }
        case removing:
        {
            std::cout << "Enter the string u want to add: ";
            std::string example = "";
            std::cin >> example;

            try
            {
                table->remove(example);
            }
            catch (MissingElementException)
            {
                std::cout << "Element is missing!\n";
            }

            break;
        }
        case checking:
        {
            std::cout << "Enter the string u want to add: ";
            std::string example = "";
            std::cin >> example;
            std::cout << "Element " << (table->exists(example)? "exists.\n" : "doesn't exist.\n");
            break;
        }
        case statistics:
        {
            table->printStatistics();
            break;
        }
        case changeHash:
        {
            std::cout << "Type:\n '1' - to use polynomial function.\n'2' - to use Jenkins hash function.\nAnything else not to change hash function: ";
            unsigned int choise = 0;
            std::cin >> choise;

            if ((choise == 1) || (choise == 2))
            {
                std::cout << "Enter module: ";
                unsigned int module = 0;
                std::cin >> module;

                if (choise == 1)
                    table->changeFunction(new StringHash(module));
                else
                    table->changeFunction(new JenkinsHash(module));
            }
        }
        case viewHelp:
        {
            help();
            break;
        }
        case wrongCommand:
        {
            std::cout << "Wrong command!\n";
            break;
        }
        case quit: { }
        }
    }
    while (option != quit);

    std::cout << "Goodbye!\n";
}

int main()
{
    ListTest listTest;
    QTest::qExec(&listTest);

    std::cout << std::endl;

    HashTableTest hashTableTest;
    QTest::qExec(&hashTableTest);

    std::cout << std::endl;

    std::cout << "This is the example, that shows how to use the HashTable class.\n"
              << "This class allows you to change hash function if you want to. It also able to rebuild the table to free up some memory.\n"
              << "Enter the amount of operations for rebuild function.(That function is called every time the add/remove/check functions are called)\n"
              << "Type '0' if you don't want hash table to rebuild.\n";

    int rebuildNumber = 0;
    std::cin >> rebuildNumber;
    HashTable *table = new HashTable(new StringHash(65536), rebuildNumber);

    dialogue(table);

    delete table;
    return 0;
}
