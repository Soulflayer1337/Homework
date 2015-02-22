#include "MyString.h"
#include "tree_queue.h" //It works like priority queue.
#include <fstream>

void dijkstra(Pair<int, int> ***way, int *numberOfWays, int n)
{
    TreeQueue *queue = createTree();
    push(queue, makePair(0, 0));

    bool *visited = new bool[n];

    for (int i = 0; i < n; i++)
        visited[i] = false;

    while (!isEmpty(queue))
    {
        Pair<int, int> *current = pop(queue);

        int length = current->first;
        int from = current->second;

        deletePair(current);

        if (visited[from])
            continue;

        visited[from] = true;
        std::cout << from + 1 << " " << length << "\n";

        for (int i = 0; i < numberOfWays[from]; i++)
            if (!visited[way[from][i]->first])
                push(queue, makePair(way[from][i]->second + length, way[from][i]->first));
    }

    deleteTree(queue);
    delete[] visited;
}

void read(std::ifstream &in, Pair<int, int> ***&way, int *&numberOfWays, int &n)
{
    int m = 0;
    in >> n >> m;

    int **helpWay = new int*[n];
    numberOfWays = new int[n];
    way = new Pair<int, int>**[n];
    for (int i = 0; i < n; i++)
    {
        helpWay[i] = new int[n];
        for (int j = 0; j < n; j++)
            helpWay[i][j] = -1;
    }

    for (int i = 0; i < m; i++)
    {
        int first = 0;
        int second = 0;
        int length = 0;
        in >> first >> second >> length;
        first--;
        second--;
        helpWay[first][second] = helpWay[second][first] = length;
    }

    for (int i = 0; i < n; i++)
    {
        numberOfWays[i] = 0;
        for (int j = 0; j < n; j++)
            numberOfWays[i] += (helpWay[i][j] != -1);

        if (numberOfWays[i] != 0)
            way[i] = new Pair<int, int>*[numberOfWays[i]];
        else
            way[i] = nullptr;

        for (int j = 0, it = 0; j < n; j++)
            if (helpWay[i][j] != -1)
                way[i][it++] = makePair(j, helpWay[i][j]);

        delete[] helpWay[i];
    }

    delete[] helpWay;
}

int main()
{
    std::cout << "Enter the file's name: ";
    MyString string;
    std::cin >> string;
    std::ifstream in(string.toChar());

    if (!in.is_open())
    {
        std::cout << "No such file in directory.\n";
        return 0;
    }

    int n = 0;
    Pair<int, int> ***way = nullptr;
    int *numberOfWays = nullptr;
    read(in, way, numberOfWays, n);
    in.close();

    dijkstra(way, numberOfWays, n);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < numberOfWays[i]; j++)
            deletePair(way[i][j]);
        if (way[i] != nullptr)
            delete[] way[i];
    }

    delete[] way;
    delete[] numberOfWays;
    return 0;
}
