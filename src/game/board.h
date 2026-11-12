#pragma once
#ifndef BOARD_H
#define BOARD_H

#include <vector>
#include <raylib.h>
#include "colors.h"

enum class MoveOptions
{
    UP,
    DOWN,
    LEFT,
    RIGTH
};

class Board
{
private:
    short cellSize;
    std::vector<std::vector<short>> board;
    std::vector<Color> colors;

    void Initialize();
    
public:
    Board();
    std::vector<std::vector<short>> getBoard();
    void placeToken(short row, short column, short playerToken);
    void removeToken(short row, short column, short playerToken);
    bool moveToken(short currentRow, short currentColumn, short playerToken, MoveOptions option);
    bool isThereMill(short playerToken);
    void reset();
    void drawBoard();
};

#endif