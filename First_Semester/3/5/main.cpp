#include <cstdio>
#include <locale.h>
#include "sortedList.h"

void commandList()
{
    printf("� ���� ��������� �������� ��������� ��������:\n\t0 - ����� �� ���������.\n\t1 - ���������� �������� � ������.\n\t\
2 - �������� �������� �� ������.\n\t3 - ����� ����������� ������.\n\t4 - ������ �������.\n");
}

int main()
{
    setlocale(LC_ALL, "Russian");
    printf("��� ������������ ���������, � ������� ���������� ��������������� ������!\n��� ����, ����� ������ ������ ������, ������� 4.\n\n");
    List *list = createList();

    bool exit = false;

    do
    {
        printf("�������, ���������� ����� �������: ");
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
                printf("������� �����, ������� ����� ��������: ");
                int value = 0;
                scanf("%d", &value);
                addElement(value, list);
                break;
            }
        case 2:
            {
                printf("������� �����, ������� ����� ������� �� ������: ");
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
                printf("����� ������� �� ����������!\n");
                break;
            }
        }

        printf("\n");
    }
    while(!exit);

    deleteList(list);
    return 0;
}
