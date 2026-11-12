#include "board.h"

namespace
{
    static constexpr short MILL_LINES[16][3][2] = {
        // External square
        // Horizontal
        {{0, 0}, {0, 3}, {0, 6}},
        {{6, 0}, {6, 3}, {6, 6}},
        // Vertical
        {{0, 0}, {3, 0}, {6, 0}},
        {{0, 6}, {3, 6}, {6, 6}},

        // Middle square
        // Horizontal
        {{1, 1}, {1, 3}, {1, 5}},
        {{5, 1}, {5, 3}, {5, 5}},
        // Vertical
        {{1, 1}, {3, 1}, {5, 1}},
        {{1, 5}, {3, 5}, {5, 5}},

        // Inside square
        // Horizontal
        {{2, 2}, {2, 3}, {2, 4}},
        {{4, 2}, {4, 3}, {4, 4}},
        // Vertical
        {{2, 2}, {3, 2}, {4, 2}},
        {{2, 4}, {3, 4}, {4, 4}},

        // Cross
        {{3, 0}, {3, 1}, {3, 2}},
        {{3, 4}, {3, 5}, {3, 6}},
        {{0, 3}, {1, 3}, {2, 3}},
        {{4, 3}, {5, 3}, {6, 3}}};
}

Board::Board()
{
    /*
       -1 = unplaceble square
        0 = placeable square
        1 = player 1 square
        2 = player 2 square
    */
    board.resize(7, std::vector<short>(7, -1));
    colors = GetCellColors();
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

    short spacesToMove = 1;

    switch (option)
    {
    case MoveOptions::UP:
        if (currentRow == 0)
            return false;
        while (true)
        {
            if (this->board[currentRow - spacesToMove][currentColumn] == -1)
            {
                spacesToMove++;
                continue;
            }
            if (this->board[currentRow - spacesToMove][currentColumn] == 0)
            {
                this->board[currentRow][currentColumn] = 0;
                this->board[currentRow - spacesToMove][currentColumn] = playerToken;
                return true;
            }
            else
            {
                return false;
            }
        }
    case MoveOptions::DOWN:
        if (currentRow == 6)
            return false;
        while (true)
        {
            if (this->board[currentRow + spacesToMove][currentColumn] == -1)
            {
                spacesToMove++;
                continue;
            }
            if (this->board[currentRow + spacesToMove][currentColumn] == 0)
            {
                this->board[currentRow][currentColumn] = 0;
                this->board[currentRow + spacesToMove][currentColumn] = playerToken;
                return true;
            }
            else
            {
                return false;
            }
        }
    case MoveOptions::LEFT:
        if (currentColumn == 0)
            return false;
        while (true)
        {
            if (this->board[currentRow][currentColumn - spacesToMove] == -1)
            {
                spacesToMove++;
                continue;
            }
            if (this->board[currentRow][currentColumn - spacesToMove] == 0)
            {
                this->board[currentRow][currentColumn] = 0;
                this->board[currentRow][currentColumn - spacesToMove] = playerToken;
                return true;
            }
            else
            {
                return false;
            }
        }
    case MoveOptions::RIGTH:
        if (currentColumn == 6)
            return false;
        while (true)
        {
            if (this->board[currentRow][currentColumn + spacesToMove] == -1)
            {
                spacesToMove++;
                continue;
            }
            if (this->board[currentRow][currentColumn + spacesToMove] == 0)
            {
                this->board[currentRow][currentColumn] = 0;
                this->board[currentRow][currentColumn + spacesToMove] = playerToken;
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

void Board::reset()
{
    Initialize();
}

void Board::drawBoard()
{
    constexpr int offset = 50;

    // Outer square
    DrawLine(offset, offset, offset + 6 * cellSize, offset, WHITE);
    DrawLine(offset, offset + 6 * cellSize, offset + 6 * cellSize, offset + 6 * cellSize, WHITE);
    DrawLine(offset, offset, offset, offset + 6 * cellSize, WHITE);
    DrawLine(offset + 6 * cellSize, offset, offset + 6 * cellSize, offset + 6 * cellSize, WHITE);

    // Middle square
    DrawLine(offset + cellSize, offset + cellSize, offset + 5 * cellSize, offset + cellSize, WHITE);
    DrawLine(offset + cellSize, offset + 5 * cellSize, offset + 5 * cellSize, offset + 5 * cellSize, WHITE);
    DrawLine(offset + cellSize, offset + cellSize, offset + cellSize, offset + 5 * cellSize,WHITE);
    DrawLine(offset + 5 * cellSize, offset + cellSize, offset + 5 * cellSize, offset + 5 * cellSize, WHITE);

    // Inner square
    DrawLine(offset + 2 * cellSize, offset + 2 * cellSize, offset + 4 * cellSize, offset + 2 * cellSize, WHITE);
    DrawLine(offset + 2 * cellSize, offset + 4 * cellSize, offset + 4 * cellSize, offset + 4 * cellSize, WHITE);
    DrawLine(offset + 2 * cellSize, offset + 2 * cellSize, offset + 2 * cellSize, offset + 4 * cellSize, WHITE);
    DrawLine(offset + 4 * cellSize, offset + 2 * cellSize, offset + 4 * cellSize, offset + 4 * cellSize, WHITE);

    // Cross connections
    DrawLine(offset, offset + 3 * cellSize, offset + 2 * cellSize, offset + 3 * cellSize, WHITE);
    DrawLine(offset + 4 * cellSize, offset + 3 * cellSize, offset + 6 * cellSize, offset + 3 * cellSize, WHITE);
    DrawLine(offset + 3 * cellSize, offset, offset + 3 * cellSize, offset + 2 * cellSize, WHITE);
    DrawLine(offset + 3 * cellSize, offset + 4 * cellSize, offset + 3 * cellSize, offset + 6 * cellSize, WHITE);

    // Pieces
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
                int cellValue = board[row][column];

                DrawCircle(
                    column * cellSize + offset,
                    row * cellSize + offset,
                    cellSize / 4,
                    colors[cellValue]);
            }
        }
    }
}