#include <fstream>
#include "MyString.h"

int visit(int numberOfNode, bool *way, bool *visited, int currentNode)
{
    if (visited[currentNode])
        return 0;

    visited[currentNode] = true;

    for (int i = 0 ; i < numberOfNode; i++)
        if (way[currentNode * numberOfNode + i])
            visit(numberOfNode, way, visited, i);
    return 1;
}

int main()
{
    std::cout << "Enter file name: ";
    MyString fileName;
    std::cin >> fileName;
    std::ifstream in(fileName.toChar());

    if (!in.is_open())
    {
        std::cout << "Can't find the file!\n";
        return 1;
    }

    int numberOfNode = 0;
    in >> numberOfNode;

    bool *way = new bool[numberOfNode * numberOfNode];
    bool *visited = new bool[numberOfNode];

    for (int i = 0; i < numberOfNode; i++)
        for (int j = 0; j < numberOfNode; j++)
            in >> way[i * numberOfNode + j];

    for (int i = 0; i < numberOfNode; i++)
        visited[i] = 0;

    int count = 0;

    for (int i = 0; i < numberOfNode; i++)
        count += visit(numberOfNode, way, visited, i);

    std::cout << "Connected component: " << count << std::endl;

    delete[] way;
    delete[] visited;
    in.close();
    return 0;
}
