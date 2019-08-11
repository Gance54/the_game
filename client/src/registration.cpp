#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QQmlComponent>

#include "registration.h"

Registration::Registration(QObject *parent) :
    QObject(parent) {
}

QString Registration::getLogin() {
    return login_;
}

QString Registration::getPassword() {
    return password_;
}

QString Registration::getPassword_rpt(){
    return password_rpt_;
}

QString Registration::getEmail(){
    return email_;
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

void Registration::setPassword_rpt(const QString &password_rpt) {
    if (password_rpt_ == password_rpt)
        return;

    password_rpt_ = password_rpt;
}

void Registration::setEmail(const QString &email) {
    if (email_ == email)
        return;

    email_ = email;
}


void Registration::onRegisterButtonClicked() {
   qDebug() << "Registration clicked";
   Registration reg;
   QQmlEngine engine;
   QQmlComponent component(&engine, "qrc:/qml/Registration.qml");
   QObject *object = component.create();
   QObject *childObject = object->findChild<QObject*>("Register");
   if(childObject)
       qDebug() << "reg object found";
   else
       qDebug() << "reg object is not found";

}
