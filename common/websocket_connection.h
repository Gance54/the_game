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

#define SERVER_URL "wss://192.168.0.169:35250"

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

private:
    QWebSocket webSocket_;
    bool connected_;
    Info info_;

};

#endif // WEBSOCKET_CONNECTION_H
