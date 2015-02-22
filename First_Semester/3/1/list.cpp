#include <cstdio>
#include "list.h"

List *createList(int &num)
{
    List *newList = new List;
    ListNode *currentElement = new ListNode;

    newList->length = num;
    currentElement->number = 0;
    newList->first = currentElement;

    for (int i = 1; i <= num; i++)
    {
        ListNode *next = new ListNode;
        next->number = i;
        currentElement->next = next;
        currentElement = next;
    }

    currentElement->next = newList->first->next;
    return newList;
}

void deleteList(List *list)
{
    delete list->first;
    delete list;
}

int suicide(List *list, int &m)
{
    ListNode *currentElement = list->first;

    while (list->length > 1)
    {
        list->length--;
        int k = 1;

        while (k < m)
        {
            k++;
            currentElement = currentElement->next;
        }

        ListNode *next = currentElement->next->next;
        delete currentElement->next;
        currentElement->next = next;
    }

    int answer = currentElement->next->number;
    delete currentElement;
    return answer;
}
