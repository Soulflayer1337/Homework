#include "MyString.h"
#include "tree_queue.h" //It works like priority queue.
#include <fstream>

void mst(Pair<int, int> ***way, int *numberOfWays, int n)
{
    int *minEdge = new int[n];
    int *selEdge = new int[n + 1];
    bool *used = new bool[n];

    const int INF = 2147483647; // 2^31 - 1

    for (int i = 0; i < n; i++)
    {
        minEdge[i] = INF;
        used[i] = false;
        selEdge[i] = -1;
    }

    minEdge[0] = 0;

    TreeQueue *queue = createTree();
    push(queue, makePair(0, 0));

    for (int i = 0; i < n; i++)
    {
        if (isEmpty(queue))
        {
            std::cout << i << " No minimum spanning tree!\n";
            break;
        }

        Pair<int, int> *current = pop(queue);
        int from = current->second;

        while (used[from] && used[selEdge[from]] && !isEmpty(queue))
        {
            deletePair(current);
            current = pop(queue);
            from = current->second;
        }

        if (used[from] && used[selEdge[from]])
        {
            deletePair(current);
            break;
        }

        used[from] = true;
        deletePair(current);

        if (selEdge[from] != -1)
            std::cout << from + 1 << " " << selEdge[from] + 1 << std::endl;

        for (int j = 0; j < numberOfWays[from]; j++)
        {
            int to = way[from][j]->first;
            int cost = way[from][j]->second;

            if (cost < minEdge[to] && !used[to])
            {
                Pair<int, int> *changeElement = makePair(minEdge[to], to);
                removeElement(queue, changeElement);
                changeElement->first = minEdge[to] = cost;
                selEdge[to] = from;
                push(queue, changeElement);
            }
        }
    }

    delete[] used;
    delete[] minEdge;
    delete[] selEdge;
    deleteTree(queue);
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

    for (int i = 0; i < n; i++)
    {
        std::cout << i << ": ";
        for (int j = 0; j < numberOfWays[i]; j++)
            std::cout << way[i][j]->first << "(" << way[i][j]->second << "),";
        std::cout << std::endl;
    }

    mst(way, numberOfWays, n);

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
