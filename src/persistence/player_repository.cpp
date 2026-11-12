#include "player_repository.h"
#include <iostream>

PlayerRepository::PlayerRepository(Database &db) : db(db)
{
}

std::vector<Player> PlayerRepository::getAllPlayers()
{
    const char *sql = "SELECT name, score FROM players ORDER BY score DESC";
    sqlite3_stmt *statement = nullptr;

    std::vector<Player> players;

    int result = sqlite3_prepare_v2(db.getConnection(), sql, -1, &statement, nullptr);
    if (result == SQLITE_OK)
    {

        while (sqlite3_step(statement) == SQLITE_ROW)
        {
            std::string name = reinterpret_cast<const char *>(sqlite3_column_text(statement, 0));
            int score = sqlite3_column_int(statement, 1);
            Player player(name);
            player.setScore(score);
            players.push_back(player);
        }
        sqlite3_finalize(statement);
    }

    return players;
}

std::optional<Player> PlayerRepository::findByName(std::string name)
{
    const char *sql = R"(
        SELECT name, score
        FROM players
        WHERE name = ?;
    )";

    sqlite3_stmt *statement = nullptr;

    sqlite3_prepare_v2(db.getConnection(), sql, -1, &statement, nullptr);
    sqlite3_bind_text(statement, 1, name.c_str(), -1, SQLITE_TRANSIENT);

    Player player;

    if (sqlite3_step(statement) == SQLITE_ROW)
    {
        const char *playerName = reinterpret_cast<const char *>(sqlite3_column_text(statement, 0));
        int score = sqlite3_column_int(statement, 1);

        player.setName(playerName);
        player.setScore(score);
    }

    sqlite3_finalize(statement);

    return std::optional(player);
}

void PlayerRepository::savePlayer(const Player &player)
{
    const char *sql = R"(
        INSERT INTO players (name, score)
        VALUES (?, ?)
        ON CONFLICT(name)
        DO UPDATE SET score = excluded.score;
    )";

    sqlite3_stmt *statement = nullptr;

    sqlite3_prepare_v2(db.getConnection(), sql, -1, &statement, nullptr);
    sqlite3_bind_text(statement, 1, player.getName().c_str(), -1, SQLITE_TRANSIENT);
    sqlite3_bind_int(statement, 2, player.getScore());
    sqlite3_step(statement);
    sqlite3_finalize(statement);
}

void PlayerRepository::deletePlayer(std::string name)
{
    const char *sql = "DELETE FROM players WHERE name = ?";

    sqlite3_stmt *statement = nullptr;

    sqlite3_prepare_v2(db.getConnection(), sql, -1, &statement, nullptr);
    sqlite3_bind_text(statement, 1, name.c_str(), -1, SQLITE_TRANSIENT);
    sqlite3_step(statement);
    sqlite3_finalize(statement);
}