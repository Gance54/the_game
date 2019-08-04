#include "login.h"

Login::Login(QObject *parent) :
    QObject(parent) {
    status_ = "Welcome!";
}

QString Login::getLogin() {
    return login_;
}

QString Login::getPassword() {
    return password_;
}

QString Login::getVersion() {
    return version_.getVersionString();
}

QString Login::getStatus() {
    return status_;
}

void Login::setStatus(QString status) {
    if (status == status_)
        return;

    status_ = status;
    emit statusChanged();
}

void Login::setLogin(const QString &login) {
    if (login_ == login)
        return;

    login_ = login;
}

void Login::setPassword(const QString &password) {
    if (password_ == password)
        return;

    password_ = password;
}

void Login::onLoginButtonClicked(const QString &login, const QString &pwd) {
    setStatus("Connecting...");
}
