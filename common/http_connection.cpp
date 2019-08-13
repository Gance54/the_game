#include <QEventLoop>
#include <QJsonObject>
#include <QMutex>
#include <QMutexLocker>

#include <QtCore/QFile>
#include <QtNetwork/QSslCertificate>
#include <QtNetwork/QSslKey>

#include "http_connection.h"

ConnectivityManager::ConnectivityManager(ConnectionType type)
{
    manager_ = new QNetworkAccessManager();

    if (type == MESSAGE_ENCRYPTED) {
        QSslConfiguration config = QSslConfiguration::defaultConfiguration();
        config.setProtocol(QSsl::TlsV1_0OrLater);
        request_.setSslConfiguration(config);
    }

    request_.setRawHeader("Content-Type", "application/json");
}

ConnectivityManager::~ConnectivityManager()
{
    delete manager_;
}

void ConnectivityManager::setRequestUrl_(QString url)
{
    request_.setUrl(QUrl(url));
}

QNetworkReply* ConnectivityManager::post(QString url, QJsonDocument json)
{
    setRequestUrl_(url);
    return manager_->post(request_, json.toJson());
}

QNetworkReply* ConnectivityManager::get(QString url)
{
    setRequestUrl_(url);
    return manager_->get(request_);
}

QJsonDocument ConnectivityManager::readJsonReply(QObject *sender)
{
    QNetworkReply *reply = qobject_cast<QNetworkReply *>(sender);
    return (QJsonDocument::fromJson(reply->readAll()));
}

QJsonDocument ConnectivityManager::readResponse_(QNetworkReply* reply)
{
    QEventLoop loop;
    QObject::connect(reply, SIGNAL(finished()), &loop, SLOT(quit()));
    loop.exec();
    return (QJsonDocument::fromJson(reply->readAll()));
}

QJsonDocument ConnectivityManager::dPost(QString url, QJsonDocument json)
{
    setRequestUrl_(url);
    QNetworkReply* reply = manager_->post(request_, json.toJson());
    return readResponse_(reply);
}

QJsonDocument ConnectivityManager::dGet(QString url)
{
    setRequestUrl_(url);
    QNetworkReply* reply = manager_->get(request_);
    return readResponse_(reply);
}
