#pragma once
#ifndef BOARD_H
#define BOARD_H

#include <vector>

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
    std::vector<std::vector<short>> board;

    void Initialize();
    
public:
    Board();
    std::vector<std::vector<short>> getBoard();
    void placeToken(short row, short column, short playerToken);
    void removeToken(short row, short column, short playerToken);
    bool moveToken(short currentRow, short currentColumn, short playerToken, MoveOptions option);
    bool isThereMill(short playerToken);
    void Reset();
};

#endif