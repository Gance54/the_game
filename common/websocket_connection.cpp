#include "websocket_connection.h"
#include <QEventLoop>

WebSocketManager::WebSocketManager() : connected_(false) {
    QSslConfiguration sslConfiguration;
    QFile certFile(QStringLiteral("E:\\repo\\Game\\Game\\client\\client.crt"));
    QFile keyFile(QStringLiteral("E:\\repo\\Game\\Game\\client\\client.key"));
    if (!certFile.open(QIODevice::ReadOnly)) {
        info_.setStatus("Certificate not found:" + certFile.fileName());
        return;
    }

    if (!keyFile.open(QIODevice::ReadOnly)) {
        info_.setStatus("Key file not found:" + certFile.fileName());
        return;
    }
    QSslCertificate certificate(&certFile, QSsl::Pem);
    QSslKey sslKey(&keyFile, QSsl::Rsa, QSsl::Pem);
    certFile.close();
    keyFile.close();
    sslConfiguration.setPeerVerifyMode(QSslSocket::VerifyNone);
    sslConfiguration.setLocalCertificate(certificate);
    sslConfiguration.setPrivateKey(sslKey);
    sslConfiguration.setProtocol(QSsl::TlsV1SslV3);
    webSocket_.setSslConfiguration(sslConfiguration);

    info_.setStatus("SSL connection prepared!");

    connect(&webSocket_, &QWebSocket::connected, [&] {
        info_.setStatus("Connected to server");
        connected_ = true;
    });

    connect(&webSocket_, &QWebSocket::disconnected, [&] {
        info_.setStatus("Disconnected from server");
        connected_ = false;
    });

}

void WebSocketManager::openUrl(QString url) {
    webSocket_.open(QUrl(url));
}

Info * WebSocketManager::getInfo() {
    return &info_;
}

int WebSocketManager::sendJson(QJsonDocument &doc) {
    if (!connected_) {
        info_.setStatus("Waiting for connection...");
        QEventLoop loop;
        QObject::connect(&webSocket_, SIGNAL(connected()), &loop, SLOT(quit()));
        loop.exec();

    }

    if (webSocket_.sendBinaryMessage(doc.toJson()) != doc.toJson().size()) {
        info_.setStatus("Failed to send data!");
        return -1;
    }

    return 0;
}
