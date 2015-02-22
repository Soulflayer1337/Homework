#include <cstdio>
#include <limits.h>
#include "sortedList.h"

// Create/Delete List

List *createList()
{
    List *newList = new List;
    ListNode *zeroElement = new ListNode;

    zeroElement->value = INT_MIN;
    zeroElement->next = nullptr;

    newList->first = zeroElement;
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

// Add/Remove Element

void addElement(int &value, List *list)
{
    ListNode *currentElement = list->first;

    while(currentElement->next != nullptr && currentElement->next->value < value)
        currentElement = currentElement->next;

    ListNode *newElement = new ListNode;
    newElement->value = value;
    newElement->next = currentElement->next;
    currentElement->next = newElement;
}


void removeElement(int &value, List *list)
{
    ListNode *currentElement = list->first->next;

    while(currentElement->next != nullptr && currentElement->next->value < value)
        currentElement = currentElement->next;

    while(currentElement->next->value == value)
    {
        ListNode *nextElement = currentElement->next->next;
        delete currentElement->next;
        currentElement->next = nextElement;
    }
}

//PrintOut

void printList(List *list)
{
    ListNode *currentElement = list->first->next;

    printf("Содержимое списка: ");
    while(currentElement != nullptr)
    {
        printf("%d ", currentElement->value);
        currentElement = currentElement->next;
    }
    printf("\n");
}
