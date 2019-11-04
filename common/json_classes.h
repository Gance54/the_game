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
    virtual ~Json (){}

protected:
    QJsonObject object_;
};

class JsonHeader : public Json {
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

private:
    MessageTag tag_;
    qulonglong ssid_;
};

class JsonMessage : public Json {
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

private:
    JsonHeader header_;
    QJsonObject payload_;
};

class JsonResponse : public Json {
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
};

class JsonRegRequest : public Json {
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

private:
    QString login_;
    QString password_;
    QString email_;
    //QString question_;
    //QString answer_;
};

#endif // JSON_CLASSES_H
