#ifndef SORTEDLIST_H_INCLUDED
#define SORTEDLIST_H_INCLUDED

struct ListNode
{
    int value;
    ListNode *next;
};

struct List
{
    ListNode *first;
};

// create/delete
List *createList();
void deleteList(List *list);

// add/remove element
void addElement(int &value, List *list);
void removeElement(int &value, List *list);

//printout
void printList(List *list);
#endif // SORTEDLIST_H_INCLUDED
