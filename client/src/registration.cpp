#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QQmlComponent>

#include "registration.h"

Registration::Registration(QObject *parent) :
    QObject(parent) {

    const QUrl url(QStringLiteral("qrc:/qml/Registration.qml"));
    engine_ = new QQmlApplicationEngine();
    engine_->rootContext()->setContextProperty("RegistrationObject", this);
    engine_->load(url);

    QObject *rootObject = engine_->rootObjects().first();
    QObject *regObject = rootObject->findChild<QObject*>("Register");

    if (regObject) {
        QObject::connect(regObject, SIGNAL(registerMe()), this, SLOT(registerMe()));
    }
}

QString Registration::getLogin() {
    return login_;
}

QString Registration::getPassword() {
    return password_;
}

QString Registration::getPassword_rpt() {
    return password_rpt_;
}

QString Registration::getEmail(){
    return email_;
}

void Registration::setLogin(const QString &login) {
    login_ = login;
}

void Registration::setPassword(const QString &password) {
    password_ = password;
}

void Registration::setPassword_rpt(const QString &password_rpt) {
    password_rpt_ = password_rpt;
}

void Registration::setEmail(const QString &email) {
    email_ = email;
}

void Registration::onRegisterButtonClicked() {
    qDebug() << "Registration clicked";

}

void Registration::registerMe() {
    qDebug() << "Registering";
}
