#include "websocket_connection.h"
WebSocketManager::WebSocketManager() {
    QSslConfiguration sslConfiguration;
    QFile certFile(QStringLiteral("E:\\repo\\Game\\Game\\client\\client.crt"));
    QFile keyFile(QStringLiteral("E:\\repo\\Game\\Game\\client\\client.key"));
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
    webSocket_.setSslConfiguration(sslConfiguration);

    connect(&webSocket_, &QWebSocket::connected, []{
        qDebug() << "Connected!";
    });
}

void WebSocketManager::openUrl(QString url) {
    webSocket_.open(QUrl(url));
}
