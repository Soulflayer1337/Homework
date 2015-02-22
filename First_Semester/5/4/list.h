#pragma once

template <typename T>
struct ListNode
{
    ListNode *next;
    T value;
};

template <typename T>
struct List
{
    ListNode<T> *first;
};

template <typename T>
bool isEmpty(List<T> *list)
{
    return (list->first == nullptr);
}

template <typename T>
List<T> *createList()
{
    List<T> *list = new List<T>;
    list->first = nullptr;
    return list;
}

template <typename T>
void deleteList(List<T> *list, void (*deleteValue)(T value) = nullptr)
{
    ListNode<T> *currentElement = list->first;

    while (currentElement != nullptr)
    {
        currentElement = currentElement->next;

        if (deleteValue != nullptr)
            deleteValue(list->first->value);

        delete list->first;
        list->first = currentElement;
    }

    delete list;
}

template <typename T>
void addElement(List<T> *list, T value)
{
    ListNode<T> *newElement = new ListNode<T>;
    newElement->next = list->first;
    newElement->value = value;
    list->first = newElement;
}

template <typename T>
void printList(List<T> *list, void (*printTParams)(T element, FILE *file), FILE *file = nullptr)
{
    ListNode<T> *currentElement = list->first;

    while (currentElement != nullptr)
    {
        printTParams(currentElement->value, file);
        currentElement = currentElement->next;
    }
}

template <typename T>
bool printFromList(List<T> *list, T example, bool (*printTParams)(T element, T example))
{
    ListNode<T> *currentElement = list->first;

    bool exist = false; //returns false if there is no elements for printout in list

    while (currentElement != nullptr) {
        if (printTParams(currentElement->value, example))
            exist = true;
        currentElement = currentElement->next;
    }

    return exist;
}
