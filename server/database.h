#ifndef DATABASE_H
#define DATABASE_H
#include "http_connection.h"

class Database {
public:
    Database();
    ~Database();

   int testDatabaseConnection();

private:
    ConnectivityManager *cManager_;
};

#endif // DATABASE_H
