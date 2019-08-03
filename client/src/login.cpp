#include "login.h"

Login::Login(QObject *parent) :
    QObject(parent) {
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

void Login::onButtonClicked(const QString &login, const QString &pwd) {
    qDebug()<<login<<pwd;
}
