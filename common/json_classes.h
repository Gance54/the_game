#ifndef JSON_CLASSES_H
#define JSON_CLASSES_H

#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include "game.h"

class JsonHeader {
public:
    JsonHeader();
    JsonHeader(MessageTag tag);
    JsonHeader(QJsonObject object);
    ~JsonHeader(){}

    void setTag(MessageTag tag);
    void setObject(QJsonObject header);
    void setSsid(qulonglong ssid);
    qulonglong getSsid();
    MessageTag getTag();
    QJsonObject object();

    void print();

private:
    MessageTag tag_;
    qulonglong ssid_;
    QJsonObject header_;
};

class JsonMessage {
public:
    JsonMessage();
    JsonMessage(QJsonDocument document);
    JsonMessage(JsonHeader header, QJsonObject payload);
    JsonMessage(MessageTag tag, QJsonObject payload);
    ~JsonMessage(){}

    void setHeader(JsonHeader header);
    void setPayload(QJsonObject payload);
    JsonHeader getHeader();
    QJsonObject getPayload();
    QJsonObject object();

    void print();

private:
    JsonHeader header_;
    QJsonObject payload_;
    QJsonObject message_;
};

class JsonRegRequest {
public:
    JsonRegRequest();
    JsonRegRequest(QJsonObject obj);
    ~JsonRegRequest(){}

    void setLogin(QString login);
    void setPassword(QString password);
    void setEmail(QString email);

    QJsonObject object();

    void print();
private:
    QString login_;
    QString password_;
    QString email_;
    QJsonObject request_;
    //QString question_;
    //QString answer_;
};

#endif // JSON_CLASSES_H
