#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>

#include "database.h"
#include "log.h"

#define DB_URL "http://127.0.0.1:5984"

Database::Database() {
    cManager_ = new ConnectivityManager();
}

Database::~Database() {
    delete cManager_;
}

int Database::testDatabaseConnection() {
    QString url = DB_URL "/login_db";
    QJsonObject loginObject;
    loginObject.insert("Login", QJsonValue::fromVariant("TestLogin"));
    loginObject.insert("Password", QJsonValue::fromVariant("TestPassword"));
    loginObject.insert("Email", QJsonValue::fromVariant("Test@email.com"));
    loginObject.insert("Question", QJsonValue::fromVariant("TestQuestion"));
    loginObject.insert("Answerd", QJsonValue::fromVariant("TestAnswer"));
    QJsonDocument doc(loginObject);

    QJsonDocument reply = cManager_->dPost(url, doc);

    QString replyString = reply.toJson(QJsonDocument::Compact);
    LOGI("DB url: %s", qPrintable(url));
    LOGI("DB reply: %s", qPrintable(replyString));

    return 0;
}
