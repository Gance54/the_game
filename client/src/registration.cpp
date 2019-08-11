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
    qDebug() << "login set" << login;
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

int verifyPwd() {

}

void Registration::onRegisterButtonClicked() {
    qDebug() << "Registration clicked";
    const QUrl url(QStringLiteral("qrc:/qml/Registration.qml"));
    QQmlApplicationEngine *engine = new QQmlApplicationEngine();
    engine->rootContext()->setContextProperty("RegistrationObject", this);

    engine->load(url);

    QObject *rootObject = engine->rootObjects().first();
    QObject *regObject = rootObject->findChild<QObject*>("Register");

    if (regObject) {
        QObject::connect(regObject, SIGNAL(registerMe()), this, SLOT(registering()));
        }


   /*
    *    QObject *rootObject = engine.rootObjects().first();
    QObject *regObject = rootObject->findChild<QObject*>("RegisterButtonObject");
    *
    *
    *
    * if(childObject)
       qDebug() << "reg object found";
   else
       qDebug() << "reg object is not found";*/

}

void Registration::registering() {
    qDebug() << "Registering";
}
