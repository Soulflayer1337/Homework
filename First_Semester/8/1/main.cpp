#include <fstream>
#include "MyString.h"

void visit(int numberOfNodes, bool *way, char *names, int current, char &letter)
{
    if (names[current] != 0)
        return;

    names[current] = letter;
    letter++;

    for (int i = 0; i < numberOfNodes; i++)
        if (way[current * numberOfNodes + i])
            visit(numberOfNodes, way, names, i, letter);
}

int main()
{
    std::cout << "Enter the file name: ";
    MyString fileName;
    std::cin >> fileName;

    std::ifstream in(fileName.toChar());

    if (!in.is_open())
    {
        std::cout << "Can't find the file!\n";
        return 1;
    }

    int numberOfNodes = 0;
    in >> numberOfNodes;
    bool *way = new bool[numberOfNodes * numberOfNodes];

    for (int i = 0; i < numberOfNodes; i++)
        for (int j = 0; j < numberOfNodes; j++)
            in >> way[i * numberOfNodes + j];

    int from = 0;
    in >> from;

    from--;

    char *names = new char[numberOfNodes];

    for (int i = 0; i < numberOfNodes; i++)
        names[i] = 0;

    char letter = 'a';
    visit(numberOfNodes, way, names, from, letter);

    for (int i = 0; i < numberOfNodes; i++)
        std::cout << i + 1 << " - " << names[i] << std::endl;

    delete[] way;
    in.close();
    return 0;
}
