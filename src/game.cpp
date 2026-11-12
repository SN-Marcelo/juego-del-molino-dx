#include "game.h"

Game::Game()
{
    board = Board();
    gameOver = false;
}

void Game::reset()
{
    gameOver = false;
    this->board.reset();
}

void Game::draw()
{
    board.drawBoard();
}

void Game::setPlayers()
{
    
}

void Game::createPlayer(std::string name)
{
    Player *newPlayer = new Player(name);
    

    delete newPlayer;
}