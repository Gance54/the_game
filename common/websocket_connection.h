#ifndef WEBSOCKET_CONNECTION_H
#define WEBSOCKET_CONNECTION_H

#include <QtWebSockets/QWebSocket>
#include <QAbstractSocket>
#include <QtCore/QFile>
#include <QtNetwork/QSslCertificate>
#include <QtNetwork/QSslKey>
#include <QObject>
#include <QString>
#include <QDebug>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include "info.h"

#define SERVER_URL "wss://78.27.147.83:35250"

class WebSocketManager : public QObject {
    Q_OBJECT
public:
    enum MessageTags {
        TAG_REGISTRATION  = 1,
        TAG_LOGIN
    };

    WebSocketManager();
    void openUrl(QString url);
    Info *getInfo();
    int sendJson(QJsonDocument &doc);

private:
    QWebSocket webSocket_;
    bool connected_;
    Info info_;

};

#endif // WEBSOCKET_CONNECTION_H
