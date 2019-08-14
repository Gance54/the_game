#include "QtWebSockets/QWebSocketServer"
#include "QtWebSockets/QWebSocket"
#include <QtCore/QDebug>
#include <QtCore/QFile>
#include <QtNetwork/QSslCertificate>
#include <QtNetwork/QSslKey>
#include <QNetworkInterface>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include "server.h"
#include "log.h"

QT_USE_NAMESPACE

//! [constructor]
Server::Server(quint16 port, QObject *parent) :
    QObject(parent),
    pWebSocketServer_(nullptr) {
    pWebSocketServer_ = new QWebSocketServer(QStringLiteral("SSL Echo Server"),
                                              QWebSocketServer::SecureMode,
                                              this);
    QSslConfiguration sslConfiguration;
    QFile certFile(QStringLiteral("localhost.crt"));
    QFile keyFile(QStringLiteral("localhost.key"));
    certFile.open(QIODevice::ReadOnly);
    keyFile.open(QIODevice::ReadOnly);
    QSslCertificate certificate(&certFile, QSsl::Pem);
    QSslKey sslKey(&keyFile, QSsl::Rsa, QSsl::Pem);
    certFile.close();
    keyFile.close();
    sslConfiguration.setPeerVerifyMode(QSslSocket::VerifyNone);
    sslConfiguration.setLocalCertificate(certificate);
    sslConfiguration.setPrivateKey(sslKey);
    sslConfiguration.setProtocol(QSsl::TlsV1SslV3);
    pWebSocketServer_->setSslConfiguration(sslConfiguration);

    QHostAddress ipAddress;
    QList<QHostAddress> ipAddressesList = QNetworkInterface::allAddresses();
    // use the first non-localhost IPv4 address
    for (int i = 0; i < ipAddressesList.size(); ++i) {
       if (ipAddressesList.at(i) != QHostAddress::LocalHost &&
           ipAddressesList.at(i).toIPv4Address()) {
           ipAddress = ipAddressesList.at(i);
           break;
       }
    }

    if (ipAddress.toString().isEmpty())
          ipAddress = QHostAddress(QHostAddress::LocalHost);

    if (pWebSocketServer_->listen(ipAddress, port)) {
	qDebug() << "SSL Echo Server listening on port" << port << ":"
		 << pWebSocketServer_->serverUrl().toString();
        connect(pWebSocketServer_, &QWebSocketServer::newConnection,
                this, &Server::onNewConnection);
        connect(pWebSocketServer_, &QWebSocketServer::sslErrors,
                this, &Server::onSslErrors);
    }
}

Server::~Server() {
    pWebSocketServer_->close();
    qDeleteAll(clients_.begin(), clients_.end());
    qDebug() << "Closing server";
}

void Server::onNewConnection() {
    QWebSocket *pSocket = pWebSocketServer_->nextPendingConnection();

    qDebug() << "Client connected:" << pSocket->peerName() << pSocket->origin();

    connect(pSocket, &QWebSocket::textMessageReceived, this, &Server::processTextMessage);
    connect(pSocket, &QWebSocket::binaryMessageReceived,
            this, &Server::processBinaryMessage);
    connect(pSocket, &QWebSocket::disconnected, this, &Server::socketDisconnected);

    clients_ << pSocket;
}

void Server::processTextMessage(QString message) {
    QWebSocket *pClient = qobject_cast<QWebSocket *>(sender());
    if (pClient) {
	qDebug () << "Text message: " << message;
    }
}

void Server::processBinaryMessage(QByteArray message) {
    QWebSocket *pClient = qobject_cast<QWebSocket *>(sender());
    if (pClient) {
	QJsonDocument doc = QJsonDocument::fromJson(message);

    }
}

void Server::socketDisconnected() {
    qDebug() << "Client disconnected";
    QWebSocket *pClient = qobject_cast<QWebSocket *>(sender());
    if (pClient) {
        clients_.removeAll(pClient);
        pClient->deleteLater();
    }
}

void Server::onSslErrors(const QList<QSslError> &) {
    qDebug() << "Ssl errors occurred";
}
