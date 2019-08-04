#include "registration.h"

Registration::Registration(QObject *parent) :
    QObject(parent) {
    status_ = "Welcome!";
}

QString Registration::getLogin() {
    return login_;
}

QString Registration::getPassword() {
    return password_;
}

QString Registration::getVersion() {
    return version_.getVersionString();
}

QString Registration::getStatus() {
    return status_;
}

void Registration::setStatus(QString status) {
    if (status == status_)
        return;

    status_ = status;
    emit statusChanged();
}

void Registration::setLogin(const QString &login) {
    if (login_ == login)
        return;

    login_ = login;
}

void Registration::setPassword(const QString &password) {
    if (password_ == password)
        return;

    password_ = password;
}

void Registration::onRegisterButtonClicked(const QString &login, const QString &pwd) {
    setStatus("Connecting...");
}
