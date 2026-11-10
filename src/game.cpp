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