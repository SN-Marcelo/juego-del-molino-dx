#include "board.h"

Board::Board()
{
    /*
       -1 = unplaceble square
        0 = placeable square
        1 = player 1 square
        2 = player 2 square
    */
    this->board.resize(7, std::vector<short>(7, -1));
    Initialize();
}

std::vector<std::vector<short>> Board::getBoard()
{
    return board;
}

void Board::placeToken(short row, short column, short playerToken)
{
    if (this->board[row][column] == 0)
        this->board[row][column] = playerToken;
}

void Board::removeToken(short row, short column, short playerToken)
{
    if (this->board[row][column] > 0 && this->board[row][column] != playerToken)
        this->board[row][column] = 0;
}

bool Board::moveToken(short currentRow, short currentColumn, short playerToken, MoveOptions option)
{
    if (this->board[currentRow][currentColumn] != playerToken)
        return false;

    switch (option)
    {
    case MoveOptions::UP:
        if(currentRow == 0)
            return false;
        short rowsUp = 1;
        while(true)
        {
            if (this->board[currentRow - rowsUp][currentColumn] == -1)
            {
                rowsUp++;
                continue;
            }
            if (this->board[currentRow - rowsUp][currentColumn] == 0)
            {
                this->board[currentRow][currentColumn] = 0;
                this->board[currentRow - rowsUp][currentColumn] = playerToken;
                return true;
            }
            else
            {
                return false;
            }
        }
    case MoveOptions::DOWN:
        if(currentRow == 6)
            return false;
        short rowsDown = 1;
        while(true)
        {
            if (this->board[currentRow + rowsDown][currentColumn] == -1)
            {
                rowsDown++;
                continue;
            }
            if (this->board[currentRow + rowsDown][currentColumn] == 0)
            {
                this->board[currentRow][currentColumn] = 0;
                this->board[currentRow + rowsDown][currentColumn] = playerToken;
                return true;
            }
            else
            {
                return false;
            }
        }
    case MoveOptions::LEFT:
        if(currentColumn == 0)
            return false;
        short columnsLeft = 1;
        while(true)
        {
            if(this->board[currentRow][currentColumn - columnsLeft] == -1)
            {
                columnsLeft++;
                continue;
            }
            if(this->board[currentRow][currentColumn - columnsLeft] == 0)
            {
                this->board[currentRow][currentColumn] = 0;
                this->board[currentRow + rowsDown][currentColumn] = playerToken;
                return true;
            }
            else
            {
                return false;
            }
        }
    case MoveOptions::RIGTH:
        if(currentColumn == 6)
            return false;
        short columnsRight = 1;
        while(true)
        {
            if(this->board[currentRow][currentColumn + columnsRight] == -1)
            {
                columnsRight++;
                continue;
            }
            if(this->board[currentRow][currentColumn + columnsRight] == 0)
            {
                this->board[currentRow][currentColumn] = 0;
                this->board[currentRow + rowsDown][currentColumn] = playerToken;
                return true;
            }
            else
            {
                return false;
            }
        }
    default:
        return false;
    }
}

bool Board::isThereMill(short playerToken)
{
    for (int i = 0; i < 16; i++)
    {
        short row1 = MILL_LINES[i][0][0];
        short column1 = MILL_LINES[i][0][1];

        short row2 = MILL_LINES[i][1][0];
        short column2 = MILL_LINES[i][1][1];

        short row3 = MILL_LINES[i][2][0];
        short column3 = MILL_LINES[i][2][1];

        if (
            board[row1][column1] == playerToken &&
            board[row2][column2] == playerToken &&
            board[row3][column3] == playerToken)
        {
            return true;
        }
    }
    return false;
}

void Board::Initialize()
{
    for (short row = 0; row < 7; row++)
    {
        for (short column = 0; column < 7; column++)
        {
            if (
                (row == column && row != 3) ||
                (row + column == 6 && row != 3) ||
                (row == 3 && column != 3) ||
                (row != 3 && column == 3))
            {
                this->board[row][column] = 0;
            }
        }
    }
}

void Board::Reset()
{
    Initialize();
}