#pragma once
#ifndef PLAYER_REPOSITORY_H
#define PLAYER_REPOSITORY_H

#include <vector>
#include <string>
#include <optional>
#include "player.h"
#include "database.h"

class PlayerRepository
{
private:
    Database &db;

public:
    PlayerRepository(Database &db);
    std::vector<Player> getAllPlayers();
    std::optional<Player> findByName(std::string name);
    void savePlayer(const Player &player);
    void deletePlayer(std::string name);
};

#endif