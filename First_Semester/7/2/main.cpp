#include "MyString.h"

int main()
{
    std::cout << "This program will show you the power of my strings!";

    //Reads the whole sentence.
    std::cout << "\nEnter the sentence: \n";
    MyString sentence;
    sentence.setParams(upToNewline);
    std::cin >> sentence;
    std::cout << "Your sentence: " << sentence << "\n\n";

    //Reads the sentence word by word.
    std::cout << "Enter another sentence: \n";
    size_t arraySize = 5;
    size_t numberOfElements = 0;
    MyString *words = new MyString[arraySize];

    while (std::cin.peek() != '\n')
    {
        MyString buf;
        std::cin >> buf;
        if (buf.isEmpty())
            continue;

        if (numberOfElements == arraySize)
        {
            arraySize += 5;
            MyString *newWords = new MyString[arraySize];

            for (size_t i = 0; i < numberOfElements; i++)
                newWords[i] = words[i];

            delete[] words;
            words = newWords;
        }

        words[numberOfElements++] = buf;
    }

    std::cout << "The words contained in your sentence: \n";
    for (size_t i = 0; i < numberOfElements; i++)
        std::cout << words[i] << std::endl;

    //Comparison and concatanation:
    MyString firstWord;
    MyString secondWord;
    std::cout << "Enter two words: ";
    std::cin >> firstWord >> secondWord;

    bool firstLess = firstWord < secondWord;

    std::cout << (firstLess ? "First" : "Second") << " word is lexicographical less than the " << (firstLess ? "second" : "first") << " word.\n";
    std::cout << "Concatanation: " << firstWord + secondWord << "\n";

    return 0;
}
