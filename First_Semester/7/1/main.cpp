#include <iostream>

int makePath(int students[], int index)
{
    if (students[index] > 2)
        students[index] = makePath(students, students[index]);

    return students[index];
}

int main()
{
    std::cout << "Wellcome to the program that will break the life of some students. :3\nEnter the number of students: ";
    int number = 0;
    std::cin >> number;

    int *students = new int[number];

    for (int i = 0; i < number; i++)
        students[i] = -1;

    std::cout << "Enter all the pairs. After the last pair enter: 0 0.\n";

    for (;;)
    {
        int from = 0;
        int to = 0;
        std::cin >> from >> to;

        if (from == 0)
            break;

        students[from - 1] = to - 1;
    }

    for (int i = 3; i < number; i++)
        makePath(students, i);

    std::cout << "\nThe following list contents information about the students and the number of their variation.\n";

    for (int i = 0; i < number; i++)
    {
        std::cout << i + 1 << " - \t";

        if (i < 3 || students[i] != -1)
            std::cout << (i < 3 ? i : students[i]) + 1 << std::endl;
        else
            std::cout << "send down.\n";
    }

    delete[] students;

    return 0;
}
