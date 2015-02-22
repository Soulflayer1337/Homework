#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED

struct ListNode
{
    ListNode *next;
    int number;
};

struct List
{
    ListNode *first;
    int length;
};

//create/delete list

List *createList(int &num);
void deleteList(List *list);

//This function can solve the problem. It also removes all elements in the list, except guard.
int suicide(List *list, int &m);
#endif // LIST_H_INCLUDED
