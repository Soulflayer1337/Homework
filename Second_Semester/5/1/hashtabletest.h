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

    void complexTest()
    {
        hashTable->add("sword");
        hashTable->add("blade");
        hashTable->add("razor");
        hashTable->add("odachi");
        hashTable->add("wakizashi");
        hashTable->add("zweihander");
        hashTable->add("morgenstern");

        QVERIFY(!hashTable->exists("tachi"));
        QVERIFY(hashTable->exists("odachi"));
        QVERIFY(hashTable->exists("morgenstern"));

        hashTable->changeFunction(new StringHash(32768));

        hashTable->add("tachi");
        hashTable->add("claymore");
        hashTable->add("uchigatana");
        hashTable->remove("morgenstern");

        QVERIFY(!hashTable->exists("morgenstern"));
        QVERIFY(hashTable->exists("tachi"));
        QVERIFY(hashTable->exists("claymore"));
    }
    // I haven't got enough fantasy for more tests :(
private:
    HashTable *hashTable;
};
