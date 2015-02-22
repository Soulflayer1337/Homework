#include <limits.h>
#include "List.h"

struct Pair
{
    MyString word;
    size_t count;
    bool was;
};

struct ListNode
{
    Pair value;
    ListNode *next;
};

struct List
{
    ListNode *first;
    size_t size;
};



List *createList()
{
    List *newList = new List;
    newList->size = 0;
    newList->first = nullptr;
    return newList;
}

void deleteList(List *list)
{
    ListNode *currentNode = list->first;

    while(currentNode != nullptr)
    {
        ListNode *nextNode = currentNode->next;
        delete currentNode;
        currentNode = nextNode;
    }

    delete list;
}



int addElement(MyString &value, ListNode *&node)
{
    if (node == nullptr)
    {
        node = new ListNode;
        node->next = nullptr;
        node->value.count = 1;
        node->value.was = false;
        node->value.word = value;
        return 1;
    }

    if (node->value.word == value)
    {
        node->value.count++;
        return 0;
    }

    return addElement(value, node->next);
}

int addElement(MyString &value, List *list)
{
    int returnValue = addElement(value, list->first);
    list->size += returnValue;
    return returnValue;
}

void printStatus(List *list)
{
    std::cout << "Maximum length: " << list->size << std::endl << "It contains: \n";

    ListNode *node = list->first;

    while (node != nullptr)
    {
        std::cout << node->value.word << " - " << node->value.count << std::endl;
        node = node->next;
    }
    std::cout << std::endl;
}

size_t lengthOfList(List *list)
{
    return list->size;
}


bool isEmpty(List *list)
{
    return (list->size == 0);
}

bool exists(List *list, MyString value)
{
    ListNode *currentNode = list->first;
    bool _exists = false;

    while (currentNode != nullptr)
    {
        if (currentNode->value.word == value)
        {
            _exists = !currentNode->value.was;
            currentNode->value.was = true;
            break;
        }
        currentNode = currentNode->next;
    }

    return _exists;
}
