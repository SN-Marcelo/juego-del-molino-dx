#pragma once
#ifndef PLAYER_H
#define PLAYER_H

#include <string>

class Player {
private:
    std::string name;
    int score;
public:
    Player();
    Player(std::string name);
    void setName(std::string name);
    std::string getName() const;
    void setScore(int score);
    void increaseScore();
    int getScore() const;
    void resetScore();
};

#endif