#include "websocket_connection.h"
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
