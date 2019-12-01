#include <QCoreApplication>
#include "server.h"
#include "database.h"
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    Server tcpServer(35250);
    Database db;
    db.testDatabaseConnection();

    return a.exec();
}
