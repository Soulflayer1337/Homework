#include <cstdio>
#include <locale.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

// �������, ��������� ������� ����
void rules()
{
    printf("� ���� \"���� � ������\" ������ ��� ��������.\n");
    printf("���� ������� ���������� �������������� �����, ��������������� ��������� ��������:\n");
    printf("\t1. ��� ����� ����� ��������.\n\t2. � ���� ���������� ������ ����� ����� �� ����.\n");
    printf("������ ������� �������� �������� ��� � �������� �����, ����������� �� ��� �� ��������.\n");
    printf("������ ������� ���������� ��� ����� � ���������� � �������, ������� � ��� �����, � ������� �����, ���\n");
    printf("\t���� - ��� �����, ������� �� ����� ������.\n\t������ - ��� �����, ��������� � �����, �� ������� �� �� ����� ������.\n");
    printf("������� ����!\n");
    return;
}

// �������, ��������� ������ � ������������ ��������
void help()
{
    printf("������ ��������� ������:\n");
    printf("\"help\" - ������� ������ ��������� ������.\n");
    printf("\"rules\" - ������� ������ ��������� ������.\n");
    printf("��� ������ ���� ��������� ������ ���� �� ���� ��������� ������, � ����������� �� ������������ ������ ����:\n");
    printf("\"play\" - ����� �������� �������� �����, ������� ������� ���������.\n");
    printf("\"computer\" - ��������� �������� �������� �����, ���������� ���������.\n");
    printf("\"exit\" - ���������� ������ ���������.\n");
    return;
}

// �������, �����������, ������������� �� ����� ��������
bool check(int &number)
{
    int num[] = {number / 1000, number / 100 % 10, number / 10 % 10, number % 10};
    return ((num[0] == num[1]) || (num[0] == num[2]) || (num[0] == num[3]) || (num[1] == num[2]) || (num[1] == num[3]) || (num[2] == num[3]));
}

// �������, �����������, �������� �� ����� �� ������� �� ���� ����������� �����
bool check(int &first, int &second, int &bullNeed, int &cowNeed)
{
    int firstArray[4] = {first / 1000, first / 100 % 10, first / 10 % 10, first % 10};
    int secondArray[4] = {second / 1000, second / 100 % 10, second / 10 % 10, second % 10};

    int bull = 0;
    int cow = 0;

    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            if (i == j)
                bull += (firstArray[i] == secondArray[j]);
            else
                cow += (firstArray[i] == secondArray[j]);

    return (bullNeed == bull && cowNeed == cow);
}

//�������, ����������� ����� ����, � ������� ��������� ���������� �����, ���������� �������������.
void computer()
{
    const int maxNum = 4536; // ���������� ��������� �����, ��������������� �������� ����.
    int variants[maxNum] = { };
    int varNum = 0;  // ��������� �� ��������� �� ��������� ������� �������

    for (int i = 1000; i < 10000; i++)
        if (!check(i))
            variants[varNum++] = i;

    while (true)
    {
        int var = variants[rand() % varNum];
        printf("�� �������� ��� ����� - %d?\n������� ���������� �����: ", var);
        int bull = 0;
        scanf("%d", &bull);

        if (bull == 4)
        {
            printf("����� ��������!\n");
            break;
        }

        printf("������� ���������� �����: ");
        int cow = 0;
        scanf("%d", &cow);

        int shift = 0;
        for (int i = 0; i < varNum; i++)
        {
            if (check(var, variants[i], bull, cow))
                variants[i - shift] = variants[i];
            else
                shift++;
        }

        varNum -= shift;

        if (varNum <= 0)
        {
            printf("�� ���������� ������ �����, ������� ������������� �� ���������� ��������!\n�� ���-�� ��������, ���������� ��� ���.\n");
            break;
        }
    }

    return;
}

//�������, �����������, ��������� ����� ��� �����
bool check(int &first, int &second)
{
    if (first < 1000 || first >= 10000 || check(first))
        printf("����� �� ������������� ��������!\n");
    else
    {
        int firstArray[4] = {first / 1000, first / 100 % 10, first / 10 % 10, first % 10};
        int secondArray[4] = {second / 1000, second / 100 % 10, second / 10 % 10, second % 10};

        int bull = 0;
        int cow = 0;

        for (int i = 0; i < 4; i++)
            for (int j = 0; j < 4; j++)
                if (i == j)
                    bull += (firstArray[i] == secondArray[j]);
                else
                    cow += (firstArray[i] == secondArray[j]);

        printf("���������� ����� - %d.\n���������� ����� - %d.\n", bull, cow);
    }

    return false;
}

//�������, ����������� ����� ����, � ������� ������������ �������� ������� �����
void player()
{
    int number = 0;

    do
    {
        number = 1000 + (rand() % 9000);
    }
    while (check(number));

    int numberEnter = 0;

    do
    {
        scanf("%d", &numberEnter);
    }
    while (numberEnter != number && !check(numberEnter, number));

    printf("�� ��������, ������ ����� - %d\n", number);
    return;
}

//������� ��������� ����
bool console()
{
    printf("������� �������: ");
    char *command = new char[20];
    scanf("%s", command);
    printf("\n\n");
    char a[][10] = {"help", "rules", "computer", "play", "exit"};
    bool exit = false;

    if (!strcmp(command, a[0]))
        help();
    else if (!strcmp(command, a[1]))
        rules();
    else if (!strcmp(command, a[2]))
        computer();
    else if (!strcmp(command, a[3]))
        player();
    else if (!strcmp(command, a[4]))
    {
        exit = true;
        printf("����� ��������!\n");
    }
    else
        printf("����� ������� �� ����������!\n ������� \"Enter\", ����� ��������� � ����� ������.");

    printf("\n\n");
    delete[] command;
    return !exit;
}

//����� �����
int main()
{
    setlocale(LC_ALL, "Russian");
    srand(time(NULL));
    printf("��� ������������ ���������� ���� \"���� � ������\"!\n����� ������ ��������� �������, ������� \"help\".\n");
    while (console());
    return 0;
}
