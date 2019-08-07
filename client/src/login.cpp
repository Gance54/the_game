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
    qDebug () << "Login accepted" << login;
    qDebug () << "Pwd accepted" << pwd;
}
