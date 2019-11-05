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
#include "json_classes.h"
#include "info.h"

#define SERVER_URL "wss://10.0.2.15:35250"

class QWebSocketEx : public QWebSocket {

};

class WebSocketManager : public QObject {
    Q_OBJECT
public:

    WebSocketManager();
    void openUrl(QString url);
    Info *getInfo();
    int sendJson(QJsonDocument &doc);
    QWebSocketEx& getSocket();
    bool connected();

signals:
    void dataReceived(QByteArray message);

public slots:
    void emitDataReceived(QByteArray message);

private:
    QWebSocketEx webSocket_;
    bool connected_;
    Info info_;
    QString url_;
};

#endif // WEBSOCKET_CONNECTION_H
