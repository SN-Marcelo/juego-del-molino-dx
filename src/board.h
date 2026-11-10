#pragma once
#ifndef BOARD_H
#define BOARD_H

#include <vector>

class Board
{
private:
    std::vector<std::vector<short>> board;
    const short MILL_LINES[16][3][2] = {

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

public:
    Board();
    std::vector<std::vector<short>> getBoard();
    void placeToken(short row, short column, short playerToken);
    void removeToken(short row, short column, short playerToken);
    bool moveToken(short currentRow, short currentColumn, short playerToken, MoveOptions option);
    bool isThereMill(short playerToken);
};

enum class MoveOptions
{
    UP,
    DOWN,
    LEFT,
    RIGTH
};

#endif