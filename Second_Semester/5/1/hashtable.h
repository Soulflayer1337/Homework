#pragma once
#include "ihashfunction.h"
#include "list.h"
#include <QString>

/**
 * @brief The HashTable class - the hash table that allows to change hash functions.
 */
class HashTable
{
public:
    /**
     * @param function - first hash function.
     * @param rebuildNum - initializes rebuildNumber. If '0' rebuild won't work at all.
     */
    HashTable(IHashFunction *function, unsigned int rebuildNum = 0);
    ~HashTable();

    /**
     * @brief add - adds new element to the current hash table
     */
    void add(const std::string &obj);
    /**
     * @brief remove - removes element from the hash table
     */
    void remove(const std::string &obj);
    /**
     * @brief exists - checks if the element exists
     */
    bool exists(const std::string &obj);
    /**
     * @brief printStatistics - prints statistics
     */
    void printStatistics() const;
    /**
     * @brief changeFunction - switches for a transmitted hash functions
     */
    void changeFunction(IHashFunction *function);
private:
    /**
     * @brief rebuild - the function used to rebuild hash table.
     */
    void rebuild();

    /**
     * @brief The Node class - the class, that contains hash table and hash function defined on it. In fact it's just a list of pairs (hash table, hash function).
     * @brief guard - the pointer to the guard element
     */
    class Node{
    public:
        Node(Node *nxt, IHashFunction *func);
        ~Node();
        Node *next;
        List *table;
        IHashFunction *function;
        /**
         * @brief numberOfElements - the number of elements contained in this hash table.
         */
        unsigned int numberOfElements;
    } *guard;

    /**
     * @brief findElement - support function. It finds the table, the transmitted element is in.
     * @return returns the pointer to the hash table.
     */
    Node *findElement(const std::string &obj);

    /**
     * @brief current - the pointer to the current hash table.
     */
    Node *current;

    /**
     * @brief pointer - the pointer to the hash table changed last.
     * @brief iterator - the index of the list changed last
     * @brief rebuildNumber - the count of the simple operations that allowed to do.
     */
    Node *pointer;
    unsigned int iterator;
    const unsigned int rebuildNumber;
};
