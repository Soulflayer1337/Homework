#include <cstdio>
#include <locale.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

// Функция, выводящая правила игры
void rules()
{
    printf("В игру \"Быки и коровы\" играют два человека.\n");
    printf("Один человек загадывает четырехзначное число, удовлетворяющее следующим правилам:\n");
    printf("\t1. Все цифры числа различны.\n\t2. В этой реализации первая цифра числа не ноль.\n");
    printf("Второй человек пытается отгадать его и называет число, построенное по тем же правилам.\n");
    printf("Первый человек сравнивает это число с загаданным и говорит, сколько в нем быков, а сколько коров, где\n");
    printf("\tБыки - это цифры, стоящие на своих местах.\n\tКоровы - это цифры, имеющиеся в числе, но стоящие не на своих местах.\n");
    printf("Удачной игры!\n");
    return;
}

// Функция, выводящая помощь о существующих командах
void help()
{
    printf("Список доступных команд:\n");
    printf("\"help\" - выводит список доступных команд.\n");
    printf("\"rules\" - выводит список доступных правил.\n");
    printf("Для начала игры требуется ввести одну из двух следующих команд, в зависимости от требующегося режима игры:\n");
    printf("\"play\" - игрок пытается отгадать число, которое загадал компьютер.\n");
    printf("\"computer\" - компьютер пытается отгадать число, загаданное человеком.\n");
    printf("\"exit\" - завершение работы программы.\n");
    return;
}

// Функция, проверяющая, удовлетворяет ли число условиям
bool check(int &number)
{
    int num[] = {number / 1000, number / 100 % 10, number / 10 % 10, number % 10};
    return ((num[0] == num[1]) || (num[0] == num[2]) || (num[0] == num[3]) || (num[1] == num[2]) || (num[1] == num[3]) || (num[2] == num[3]));
}

// Функция, проверяющая, подходит ли число из массива на роль загаданного числа
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

//Функция, реализующая режим игры, в котором компьютер отгадывает число, загаданное пользователем.
void computer()
{
    const int maxNum = 4536; // Количество вариантов чисел, удовлетворяющих условиям игры.
    int variants[maxNum] = { };
    int varNum = 0;  // Указатель на следующий за последним элемент массива

    for (int i = 1000; i < 10000; i++)
        if (!check(i))
            variants[varNum++] = i;

    while (true)
    {
        int var = variants[rand() % varNum];
        printf("Вы загадали это число - %d?\nВведите количество быков: ", var);
        int bull = 0;
        scanf("%d", &bull);

        if (bull == 4)
        {
            printf("Раунд закончен!\n");
            break;
        }

        printf("Введите количество коров: ");
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
            printf("Не существует такого числа, которое удовлетворяло бы предыдущим условиям!\nВы где-то ошиблись, попробуйте еще раз.\n");
            break;
        }
    }

    return;
}

//Функция, проверяющая, насколько схожи два числа
bool check(int &first, int &second)
{
    if (first < 1000 || first >= 10000 || check(first))
        printf("Число не удовлетворяет условиям!\n");
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

        printf("Количество быков - %d.\nКоличество коров - %d.\n", bull, cow);
    }

    return false;
}

//Функция, реализующая режим игры, в котором пользователь пытается угадать число
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

    printf("Вы выиграли, верное число - %d\n", number);
    return;
}

//Функция основного меню
bool console()
{
    printf("Введите команду: ");
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
        printf("Всего хорошего!\n");
    }
    else
        printf("Такой команды не существует!\n Нажмите \"Enter\", чтобы вернуться к вводу команд.");

    printf("\n\n");
    delete[] command;
    return !exit;
}

//Точка входа
int main()
{
    setlocale(LC_ALL, "Russian");
    srand(time(NULL));
    printf("Вас приветствует консольная игра \"Быки и коровы\"!\nЧтобы узнать доступные команды, введите \"help\".\n");
    while (console());
    return 0;
}
