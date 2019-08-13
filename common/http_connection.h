#ifndef DB_CONNECTION_H
#define DB_CONNECTION_H

#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkRequest>
#include <QtNetwork/QNetworkReply>
#include <QtNetwork/QSsl>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>

class ConnectivityManager {
public:
    enum ConnectionType {
        MESSAGE_ENCRYPTED = 1,
        MESSAGE_PLAIN
    };

    ConnectivityManager(ConnectionType type = MESSAGE_PLAIN);
    ~ConnectivityManager();

    QNetworkReply *post(QString url, QJsonDocument json);
    QNetworkReply *get(QString url);
    QJsonDocument readJsonReply(QObject *sender);

    QJsonDocument dPost(QString url, QJsonDocument json);
    QJsonDocument dGet(QString url);

private:
    QNetworkRequest request_;
    QNetworkAccessManager *manager_;

    void setRequestUrl_(QString url);
    QJsonDocument readResponse_(QNetworkReply* reply);
};

#endif // DB_CONNECTION_H
