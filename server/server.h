#ifndef SERVER_H
#define SERVER_H

#include <QTcpServer>
#include <QtNetwork>

class Server : public QObject
{
    Q_OBJECT

public:
    Server();

private slots:
    void sendUserInitialData();

private:
    bool initialized_;
    int version_;
    QTcpServer *tcpServer_ = nullptr;
    QNetworkSession *networkSession_ = nullptr;
};

#endif // SERVER_H
