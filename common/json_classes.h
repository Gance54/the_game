#ifndef JSON_CLASSES_H
#define JSON_CLASSES_H

#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include "game.h"

class Json {
public:
    virtual QJsonObject object() = 0;
    virtual void print();

protected:
    QJsonObject object_;
};

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

class JsonResponse {
public:
    JsonResponse();
    JsonResponse(QJsonObject obj);
    JsonResponse(ErrorCode err);
    ~JsonResponse();

    ErrorCode getError();
    QJsonObject getExtra();
    QJsonObject object();
    void setError(ErrorCode err);
    void setExtra(QJsonObject extra);
    QString getString();

private:
    ErrorCode error_;
    QJsonObject extra_;
    QJsonObject response_;
};

class JsonRegRequest {
public:
    JsonRegRequest();
    JsonRegRequest(QJsonObject obj);
    ~JsonRegRequest(){}

    QString getLogin();
    QString getPassword();
    QString getEmail();

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
