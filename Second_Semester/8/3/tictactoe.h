#pragma once
#include "../../../Some_Useful_Things/Containers/vector.h"

class SmallSizeException
{
};

class GameIsOverException
{
};

/// \brief The Marks enum - the enum of status markers
enum Marks
{
    empty = 0,
    naught,
    cross,
    draw
};

/// \brief The TicTacToe class - the class for the game
class TicTacToe
{
public:
    /**
     * @brief TicTacToe - creates the game with parameters
     * @param height - the height of the field
     * @param width - the width of the field
     * @param _numberInARow - the number of the marks in the row to win
     */
    TicTacToe(unsigned int height, unsigned int width, unsigned int _numberInARow);
    ~TicTacToe();

    /// \brief markInTheCell - returns the Mark, contained in the cell
    Marks markInTheCell(unsigned int row, unsigned int column) const;
    /// \brief marked - checks if the cell is marked by naught or cross
    bool marked(unsigned int row, unsigned int column) const;
    /// \brief markTheSpot - marks the cell by the currentMark
    void markTheSpot(unsigned int row, unsigned int column);

    /// \brief getWinner - returns the winner
    Marks getWinner();
private:
    /// \brief countTheRow - support function. Counts the number of the elements in the row
    void countTheRow(int row, int column, int rowInc, int columnInc);

    unsigned int emptyCells;
    const unsigned int numberInARow;
    Vector<Vector<Marks> >  *field;
    Marks currentMark;
    Marks winner;
};
