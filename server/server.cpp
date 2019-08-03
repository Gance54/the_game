#include "server.h"
#include "log.h"

#define VERSION 100

Server::Server(){
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
    // if we did not find one, use IPv4 localhost
    if (ipAddress.toString().isEmpty())
	ipAddress = QHostAddress(QHostAddress::LocalHost);

    tcpServer_ = new QTcpServer(this);
    quint16 port = 35250;
    if (!tcpServer_->listen(ipAddress, port)) {
	LOGE("Fortune Server unable to start the server: %s", qPrintable(tcpServer_->errorString()));
	return;
    }

    LOGI("The server is running on %s:%s",qPrintable(ipAddress.toString()),
	    qPrintable(QString::number(tcpServer_->serverPort())));

    connect(tcpServer_, &QTcpServer::newConnection, this, &Server::sendUserInitialData);
}

void Server::sendUserInitialData() {
    QByteArray block;
    QDataStream out(&block, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_5_10);
    out << version_;
}
