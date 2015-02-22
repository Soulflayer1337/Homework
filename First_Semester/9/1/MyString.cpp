#include "MyString.h"

/*
 * Constructor
 */
MyString::MyString()
{
    _symbols = nullptr;
    _length = 0;
    _readingParams = withoutSeparators;
}

MyString::MyString(const MyString &example)
{
    _length = example._length;
    _sizeOfArray = example._sizeOfArray;
    _readingParams = example._readingParams;

    if (_length != 0) {
        _symbols = new char[_sizeOfArray];
        strcpy(_symbols, example._symbols);
    }
}

MyString::MyString(const char *string)
{
    _readingParams = withoutSeparators;
    _length = strlen(string);
    _sizeOfArray = 1;

    while (_length >= _sizeOfArray)
        _sizeOfArray <<= 1;

    _symbols = new char[_sizeOfArray];
    strcpy(_symbols, string);
}

//Setting function
void MyString::setParams(readingOptions params)
{
    _readingParams = params;
}

const MyString &operator +=(MyString &left, const char *right)
{
    left += MyString(right);
    return left;
}

const MyString operator +(const MyString &left, const char *right)
{
    return (left + MyString(right));
}

//Comparison
int compare(const MyString &left, const MyString &right)
{
    return strcmp(left._symbols, right._symbols);
}

bool operator <(const MyString &left, const MyString &right)
{
    return (strcmp(left._symbols, right._symbols) < 0);
}

bool operator >(const MyString &left, const MyString &right)
{
    return (strcmp(left._symbols, right._symbols) > 0);
}

bool operator <=(const MyString &left, const MyString &right)
{
    return (strcmp(left._symbols, right._symbols) <= 0);
}

bool operator >=(const MyString &left, const MyString &right)
{
    return (strcmp(left._symbols, right._symbols) >= 0);
}

bool operator ==(const MyString &left, const MyString &right)
{
    return (strcmp(left._symbols, right._symbols) == 0);
}

bool operator !=(const MyString &left, const MyString &right)
{
    return (strcmp(left._symbols, right._symbols) != 0);
}

//Concatenation
const MyString operator +(const MyString &left, const MyString &right)
{
    MyString newString;
    newString._length = left._length + right._length;
    newString._sizeOfArray = (left._sizeOfArray > right._sizeOfArray ? left._sizeOfArray : right._sizeOfArray);
    newString._readingParams = left._readingParams;

    while (newString._length >= newString._sizeOfArray)
        newString._sizeOfArray <<= 1;

    if (newString._length)
        newString._symbols = new char[newString._sizeOfArray];

    if (left._length)
        strcpy(newString._symbols, left._symbols);

    if (right._length)
        strcpy(newString._symbols + left._length, right._symbols);

    return newString;
}

const MyString &operator +=(MyString &left, const MyString &right)
{
    left = left + right;
    return left;
}

//copying
const MyString &MyString::operator =(const MyString &right)
{
    _length = right._length;
    _sizeOfArray = right._sizeOfArray;
    _readingParams = right._readingParams;

    if (_symbols != nullptr)
        delete[] _symbols;

    _symbols = new char[_sizeOfArray];
    strcpy(_symbols, right._symbols);
    return *this;
}

const MyString clone(const MyString &right)
{
    return MyString(right);
}

char &MyString::operator [](size_t index)
{
    return _symbols[index];
}
bool isSeparator(char symb, readingOptions param)
{
    return (((symb == ' ') || (symb == '\t')) && (param != upToNewline)) || (symb == '\n');
}

bool mustBeIgnored(char symb, readingOptions param)
{
    return ((param == onlyLetters) && !(('a' <= symb && symb <= 'z') || ('A' <= symb && symb <= 'Z')));
}

std::istream &operator>>(std::istream &stream, MyString &obj)
{
    delete[] obj._symbols;
    obj._symbols = new char[2];
    obj._sizeOfArray = 1;
    obj._length = 0;

    if (obj._readingParams != upToNewline)
        while (!stream.eof() && isSeparator(stream.peek(), withoutSeparators))
            stream.ignore();

    while (!stream.eof() && !isSeparator(stream.peek(), obj._readingParams))
    {
        if (mustBeIgnored(stream.peek(), obj._readingParams))
        {
            stream.ignore();
            continue;
        }

        if (stream.eof())
            break;

        if (obj._length + 1 == obj._sizeOfArray)
        {
            obj._sizeOfArray <<= 1;
            char *newSymbols = new char[obj._sizeOfArray];
            memcpy(newSymbols, obj._symbols, obj._length);
            delete[] obj._symbols;
            obj._symbols = newSymbols;
        }

        obj._symbols[obj._length++] = stream.get();
    }

    if (!stream.eof() && obj._readingParams == upToNewline)
        stream.ignore();

    if (obj._length == 0)
    {
        delete[] obj._symbols;
        obj._symbols = nullptr;
    }
    else
        obj._symbols[obj._length] = '\0';

    return stream;
}

std::ostream &operator<<(std::ostream &stream, const MyString &obj)
{
    if (obj._symbols != nullptr)
        stream << obj._symbols;
    return stream;
}

size_t MyString::length()
{
    return _length;
}

bool MyString::isEmpty()
{
    return _length == 0;
}

MyString MyString::substring(size_t fromIndex, size_t sizeOfSubstring)
{
    MyString newString;

    newString._length = (sizeOfSubstring && (sizeOfSubstring > (_length - fromIndex + 1)) ? _length - fromIndex + 1 : sizeOfSubstring);
    while (newString._sizeOfArray < newString._length)
        newString._sizeOfArray <<= 1;

    newString._readingParams = withoutSeparators;
    newString._symbols = new char[_sizeOfArray];
    memcpy(newString._symbols, _symbols + fromIndex, newString._length);

    return newString;
}

char *MyString::toChar()
{
    if (_length == 0)
        return nullptr;

    char *newCharString = new char[_length];
    strcpy(newCharString, _symbols);

    return newCharString;
}

MyString::~MyString()
{
    if (_symbols != nullptr)
        delete[] _symbols;
}

