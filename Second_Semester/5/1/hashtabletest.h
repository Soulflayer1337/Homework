#pragma once

#include <QtCore/QObject>
#include <QtTest/QtTest>
#include "hashtable.h"
#include "jenkinshash.h"
#include "stringhash.h"

class HashTableTest : public QObject
{
    Q_OBJECT
public:
    explicit HashTableTest(QObject *parent = 0) :QObject(parent) {}

private slots:
    void init()
    {
        hashTable = new HashTable(new JenkinsHash(65536), 10000);
    }

    void cleanup()
    {
        delete hashTable;
    }

    void testExistsInEmpty()
    {
        QVERIFY(!hashTable->exists("blade"));
    }

    void testAddTo()
    {
        hashTable->add("blade");
        QVERIFY(hashTable->exists("blade"));
    }

    void testExists()
    {
        hashTable->add("blade");
        QVERIFY(!hashTable->exists("sword"));
    }

    void testRemove()
    {
        hashTable->add("blade");
        hashTable->remove("blade");
        QVERIFY(!hashTable->exists("blade"));
    }

    void testChangedCorrect()
    {
        hashTable->add("blade");
        hashTable->changeFunction(new StringHash(32768));
        QVERIFY(hashTable->exists("blade"));
    }

    void testChangedCorrect2()
    {
        hashTable->add("blade");
        hashTable->changeFunction(new StringHash(32768));
        hashTable->remove("blade");
        QVERIFY(!hashTable->exists("blade"));
    }

private:
    HashTable *hashTable;
};
