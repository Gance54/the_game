#ifndef SERVER_H
#define SERVER_H

#include <QTcpServer>
#include <QWebSocketServer>

#include "database.h"
class Server : public QObject
{
    Q_OBJECT

public:
    explicit Server(quint16 port, QObject *parent = nullptr);
    ~Server() override;

private Q_SLOTS:
    void onNewConnection();
    void processTextMessage(QString message);
    void processBinaryMessage(QByteArray message);
    void socketDisconnected();
    void onSslErrors(const QList<QSslError> &errors);

private:
    QWebSocketServer *pWebSocketServer_;
    QList<QWebSocket *> clients_;
    Database db_;


};

#endif // SERVER_H
