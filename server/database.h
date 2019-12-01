#ifndef DATABASE_H
#define DATABASE_H
#include "http_connection.h"
#include "json_classes.h"
class Database {
public:
    Database();
    ~Database();

   int testDatabaseConnection();
   ErrorCode::Code ProcessRegistrationRequest(QJsonObject req);

private:
    ConnectivityManager *cManager_;
};

#endif // DATABASE_H
