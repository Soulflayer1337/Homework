#pragma once

#include <QtCore/QObject>
#include <QtTest/QtTest>
#include "tictactoe.h"

class TicTacToeTest : public QObject
{
    Q_OBJECT
public:
    explicit TicTacToeTest(QObject *parent = 0) : QObject(parent) { }

private slots:
    void init()
    {
        game = new TicTacToe(3, 3, 3);
    }

    void cleanup()
    {
        delete game;
    }

    void markTest()
    {
        game->markTheSpot(2, 2);
        QVERIFY(game->marked(2, 2));
        QVERIFY(!game->marked(1, 2));
    }

    void markInTheCellTest()
    {
        game->markTheSpot(2, 2);
        QCOMPARE(game->markInTheCell(2, 2), cross);
        QCOMPARE(game->markInTheCell(2, 1), empty);
        game->markTheSpot(1, 2);
        QCOMPARE(game->markInTheCell(1, 2), naught);
    }

    void gameTest()
    {
        game->markTheSpot(0, 0);
        game->markTheSpot(0, 1);
        game->markTheSpot(1, 1);
        game->markTheSpot(2, 2);
        game->markTheSpot(1, 0);
        game->markTheSpot(2, 0);
        game->markTheSpot(1, 2);
        QCOMPARE(game->getWinner(), cross);
    }

    void gameIsOverTest()
    {
        game->markTheSpot(0, 0);
        game->markTheSpot(0, 1);
        game->markTheSpot(1, 1);
        game->markTheSpot(2, 2);
        game->markTheSpot(1, 0);
        game->markTheSpot(2, 0);
        game->markTheSpot(1, 2);

        bool gameIsOver = false;

        try
        {
            game->markTheSpot(2, 1);
        }
        catch (GameIsOverException &)
        {
            gameIsOver = true;
        }

        QVERIFY(gameIsOver);
    }

    void drawTest()
    {
        game->markTheSpot(0, 0);
        game->markTheSpot(1, 1);
        game->markTheSpot(1, 0);
        game->markTheSpot(2, 0);
        game->markTheSpot(0, 2);
        game->markTheSpot(0, 1);
        game->markTheSpot(2, 1);
        game->markTheSpot(2, 2);
        game->markTheSpot(1, 2);

        QCOMPARE(game->getWinner(), draw);
    }
private:
    TicTacToe *game;
};
