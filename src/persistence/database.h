#pragma once
#ifndef DATABASE_H
#define DATABASE_H

#include "sqlite3.h"

class Database
{
private:
    sqlite3* db;

public:
    Database(const char* path);
    ~Database();

    sqlite3* getConnection();
    void createTables();
};

#endif