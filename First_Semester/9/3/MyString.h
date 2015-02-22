#pragma once
#include <iostream>
#include <string.h>

enum readingOptions {upToNewline,   // This option allows to read a line completely.
                    withoutSeparators,  // This option allows to read the part of the string before the spaces or tabulation. The following works almost the same way.
                    onlyLetters};       // Ignores everything except letters. 'a'-'z', 'A'-'Z'

class MyString
{
private:
    char *_symbols;         //Array of symbols
    size_t _length;         //Length of the string
    size_t _sizeOfArray;    //Size of array
    readingOptions _readingParams;       //Reading param
public:
    //Constructor
    MyString();                 //Creates empty string
    MyString(const MyString &example); //Creates copy of another string
    MyString(const char *string);     //Creates MyString from C-string

    //Function sets the parameters of reading
    void setParams(readingOptions params);

    //Comparison
    friend int compare(const MyString &left, const MyString &right); //Lexicographical comparison
    friend bool operator <(const MyString &left, const MyString &right);
    friend bool operator >(const MyString &left, const MyString &right);
    friend bool operator <=(const MyString &left, const MyString &right);
    friend bool operator >=(const MyString &left, const MyString &right);
    friend bool operator ==(const MyString &left, const MyString &right);
    friend bool operator !=(const MyString &left, const MyString &right);

    //Concatenation
    friend const MyString operator +(const MyString &left, const MyString &right);
    friend const MyString &operator +=(MyString &left, const MyString &right);
    friend const MyString operator +(const MyString &left, const char *right);
    friend const MyString &operator +=(MyString &left, const char *right);

    //Creates copy
    const MyString &operator =(const MyString &right);
    friend const MyString clone(const MyString &right);

    //Indexing
    char &operator [](size_t index);  //Return _symbols[index] if index is less

    //Stream operators
    friend std::istream &operator>>(std::istream &stream, MyString &obj);
    friend std::ostream &operator<<(std::ostream &stream, const MyString &obj);

    // Some other functions:
    size_t length();  //Returns size of string
    bool isEmpty(); //Checks if string is empty
    MyString substring(size_t fromIndex, size_t sizeOfSubstring = 0);   //creates substring
    char *toChar();     //returns pointer to char

    //Destructor
    ~MyString();
};
