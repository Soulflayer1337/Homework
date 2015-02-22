#include "contact.h"

void deleteContact(Contact obj)
{
    if (obj.name != nullptr)
        delete[] obj.name;

    if (obj.number != nullptr)
        delete[] obj.number;
}

bool printName(Contact element, Contact example)
{
    bool elementExist = false;

    if (isTheSame(element.number, example.number))
    {
        printf("%s\n", element.name);
        elementExist = true;
    }

    return elementExist;
}

bool printNumber(Contact element, Contact example)
{
    bool elementExist = false;

    if (isTheSame(element.name, example.name))
    {
        printf("%s\n", element.number);
        elementExist = true;
    }

    return elementExist;
}


void readFromFile(FILE *file, Handbook handbook)
{
    while (!feof(file))
    {
        Contact newContact;
        newContact.number = readUntil(' ', file);
        newContact.name = readUntil('\n', file);
        if (newContact.name != nullptr && newContact.number != nullptr)
            addElement(handbook, newContact);
    }
}

void writeContact(Contact element, FILE *file)
{
    if (file != nullptr)
        fprintf(file, "%s %s\n", element.number, element.name);
    else
        printf("%s %s\n", element.number, element.name);
}

Contact readFromConsole()
{
    Contact newElement;
    printf("Enter name: ");
    newElement.name = readUntil('\n');
    printf("Enter number: ");
    newElement.number = readUntil('\n');
    return newElement;
}

void saveToFile(FILE *file, Handbook handbook)
{
    file = fopen("contacts.txt", "w");
    printList(handbook, writeContact, file);
    fclose(file);
}
