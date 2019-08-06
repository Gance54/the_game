#include "info.h"


Info::Info(QObject *parent) :
    QObject(parent) {
    status_ = "Welcome!";
}

QString Info::getLogin() {
    return login_;
}

QString Info::getPassword() {
    return password_;
}

QString Info::getVersion() {
    return version_.getVersionString();
}

QString Info::getStatus() {
    return status_;
}

void Info::setStatus(QString status) {
    if (status == status_)
        return;

    status_ = status;
    emit statusChanged();
}

void Info::setLogin(const QString &login) {
    if (login_ == login)
        return;

    login_ = login;
}

void Info::setPassword(const QString &password) {
    if (password_ == password)
        return;

    password_ = password;
}

void Info::onLoginButtonClicked(const QString &login, const QString &pwd) {
    setStatus("Connecting...");
}

void Info::onRegisterButtonClicked(const QString &login, const QString &pwd) {
    setStatus("Registration...");
}
