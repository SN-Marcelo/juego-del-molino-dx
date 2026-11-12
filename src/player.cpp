#include "player.h"

Player::Player()
{
    name = "";
    score = 0;
}

Player::Player(std::string name)
{
    this->name = name;
    score = 0;
}

void Player::setName(std::string name)
{
    this->name = name;
}

std::string Player::getName() const 
{
    return name;
}

void Player::setScore(int score)
{
    this->score = score;
}

void Player::increaseScore()
{
    score++;
}

int Player::getScore() const 
{
    return score;
}

void Player::resetScore()
{
    score = 0;
}