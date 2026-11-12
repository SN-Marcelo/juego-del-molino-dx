#pragma once
#ifndef GAME_H
#define GAME_H

#include "board.h"
#include "player.h"

class Game
{
private:
    bool gameOver;
    Board board;
    Player player1;
    Player player2;

public:
    Game();
    void reset();
    void draw();
    
    //Player related
    void setPlayers();
    void createPlayer(std::string name);
};

#endif