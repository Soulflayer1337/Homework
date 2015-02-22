#include <cstdio>
#include <locale.h>
#include "sortedList.h"

void commandList()
{
    printf("В этой программе доступны следующие комманды:\n\t0 - выход из программы.\n\t1 - Добавление элемента в список.\n\t\
2 - Удаление элемента из списка.\n\t3 - Вывод содержимого списка.\n\t4 - Список комманд.\n");
}

int main()
{
    setlocale(LC_ALL, "Russian");
    printf("Вас приветствует программа, в которой реализован отсортированный список!\nДля того, чтобы узнать список команд, введите 4.\n\n");
    List *list = createList();

    bool exit = false;

    do
    {
        printf("Введите, пожалуйста номер команды: ");
        int command = 0;
        scanf("%d", &command);

        switch(command)
        {
        case 0:
            {
                exit = true;
                break;
            }
        case 1:
            {
                printf("Введите число, которое нужно добавить: ");
                int value = 0;
                scanf("%d", &value);
                addElement(value, list);
                break;
            }
        case 2:
            {
                printf("Введите число, которое нужно удалить из списка: ");
                int value = 0;
                scanf("%d", &value);
                removeElement(value, list);
                break;
            }
        case 3:
            {
                printList(list);
                break;
            }
        case 4:
            {
                commandList();
                break;
            }
        default:
            {
                printf("Такой команды не существует!\n");
                break;
            }
        }

        printf("\n");
    }
    while(!exit);

    deleteList(list);
    return 0;
}
