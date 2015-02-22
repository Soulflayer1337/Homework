#include <wchar.h>
#include <locale.h>
#include "stack.h"
#include "queue.h"
#include "calculate.h"
#include "change_format.h"

//Точка входа в программу
int main()
{
    setlocale(LC_ALL, "Russian");
    wprintf(L"Вас приветствует программа, преобразующая выражение из инфиксного в постфиксное и вычисляющая его значение.\n\
Если последовательность скобок в вашем выражении будет нарушена, выражение может быть посчитано неверно.\n\
В связи с этим при нарушенной последовательности скобок, результат выражения посчитан не будет!\n");
    Queue<char> *queue = createQueue<char>();

    if (postfixToInfix(queue))
        wprintf(L"\nВ вашем выражении была нарушена последовательность скобок!\
Выражение могло быть переведено неверно, из-за чего результат выражения посчитан не будет.");
    else
        countInfix(queue);

    deleteQueue(queue);
    return 0 ;
}
