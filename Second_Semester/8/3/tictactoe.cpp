#include "tictactoe.h"

TicTacToe::TicTacToe(unsigned int height, unsigned int width, unsigned int _numberInARow) : emptyCells(height * width), numberInARow(_numberInARow), field(nullptr), currentMark(cross), winner(empty)
{
    if (height < 2 || width < 2 || numberInARow < 2)
        throw SmallSizeException();

    field = new Vector<Vector<Marks> >(height, Vector<Marks>(width, empty));
}

TicTacToe::~TicTacToe()
{
    delete field;
}

Marks TicTacToe::markInTheCell(unsigned int row, unsigned int column) const
{
    return ((*field)[row][column]);
}

bool TicTacToe::marked(unsigned int row, unsigned int column) const
{
    return ((*field)[row][column] != empty);
}

void TicTacToe::markTheSpot(unsigned int row, unsigned int column)
{
    if (winner != empty)
        throw GameIsOverException();

    if (!marked(row, column))
    {
        (*field)[row][column] = currentMark;
        emptyCells--;

        countTheRow(row, column, 1, 1);
        countTheRow(row, column, 1, 0);
        countTheRow(row, column, 1, -1);
        countTheRow(row, column, 0, 1);

        currentMark = (currentMark == cross ? naught : cross);

        if (!emptyCells && winner == empty)
            winner = draw;
    }
}

Marks TicTacToe::getWinner()
{
    return winner;
}

void TicTacToe::countTheRow(int row, int column, int rowInc, int columnInc)
{
    if (winner != empty)
        return;

    unsigned int numberInTheRow = 1;
    int height = field->getLength();
    int width = (*field)[0].getLength();

    int currentRow = row + rowInc;
    int currentColumn = column + columnInc;

    while (currentRow >= 0 && currentColumn >= 0 && currentRow < height && currentColumn < width && (*field)[row][column] == (*field)[currentRow][currentColumn])
    {
        numberInTheRow++;
        currentColumn += columnInc;
        currentRow += rowInc;
    }

    currentRow = row - rowInc;
    currentColumn = column - columnInc;

    while (currentRow >= 0 && currentColumn >= 0 && currentRow < height && currentColumn < width && (*field)[row][column] == (*field)[currentRow][currentColumn])
    {
        numberInTheRow++;
        currentColumn -= columnInc;
        currentRow -= rowInc;
    }

    if (numberInTheRow >= numberInARow)
        winner = currentMark;
}
