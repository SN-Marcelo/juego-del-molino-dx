#pragma once
#ifndef GAME_H
#define GAME_H

#include "board.h"

class Game
{
private:
    bool gameOver;
    Board board;

public:
    Game();
    void reset();
    void draw();
};

#endif