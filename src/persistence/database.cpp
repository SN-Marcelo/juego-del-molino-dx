#include "database.h"
#include <iostream>

Database::Database(const char *path)
{
    int connection = sqlite3_open(path, &db);
    if (connection != SQLITE_OK)
    {
        std::cerr << "Error while opening database"
                  << sqlite3_errmsg(db)
                  << std::endl;

        db = nullptr;
    }
}

Database::~Database()
{
    if (db != nullptr)
    {
        sqlite3_close(db);
    }
}

sqlite3 *Database::getConnection()
{
    return db;
}

void Database::createTables()
{
    const char *sql = R"(
        CREATE TABLE IF NOT EXISTS players (
            id INTEGER PRIMARY KEY AUTOINCREMENT,
            name TEXT NOT NULL UNIQUE,
            score INTEGER NOT NULL DEFAULT 0
        );
    )";

    char *errorMessage = nullptr;

    int result = sqlite3_exec(db, sql, nullptr, nullptr, &errorMessage);

    if (result != SQLITE_OK)
    {
        std::cerr << "Error creating players table: "
                  << errorMessage
                  << std::endl;

        sqlite3_free(errorMessage);
    }
}