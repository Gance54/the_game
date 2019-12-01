#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QQmlComponent>
#include <QCryptographicHash>

#include "registration.h"
#include "json_classes.h"
#include "game.h"


//TODO: replace info object from socket manager to registration
Registration::Registration(QObject *parent) :
    QObject(parent) {

    const QUrl url(QStringLiteral("qrc:/qml/Registration.qml"));
    engine_.rootContext()->setContextProperty("RegistrationObject", this);
    engine_.rootContext()->setContextProperty("statusObject", socketManager_.getInfo());

    engine_.load(url);

    QObject *rootObject = engine_.rootObjects().first();
    QObject *regObject = rootObject->findChild<QObject*>("Register");

    if (regObject) {
        QObject::connect(regObject, SIGNAL(registerMe()), this, SLOT(registerMe()));
    }

    socketManager_.openUrl(SERVER_URL);
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

void Registration::registerMe() {
    if (verify()) {
        socketManager_.getInfo()->setStatus("Please fill form correctly!");
        return;
    }

    if (!socketManager_.connected()) {
        socketManager_.openUrl(SERVER_URL);
    }

    JsonRegRequest request;
    request.setLogin(login_);
    request.setPassword(password_);
    request.setEmail(email_);

    JsonMessage message(MessageTag::TAG_REGISTRATION, request.object());
    message.print();
    QJsonDocument doc(message.object());

    socketManager_.sendJson(doc);

    connect(&socketManager_, &WebSocketManager::dataReceived,
            this, &Registration::processRegistrationResponse);
}

int Registration::verify() {
    if (login_.isEmpty() || QString::compare(password_, password_rpt_) ||
        email_.isEmpty()) {
        qDebug("Failed to verify object");
        return -1;
    }
    return 0;
}

void Registration::processRegistrationResponse(QByteArray message) {
    QJsonDocument doc = QJsonDocument::fromJson(message);
    qDebug("message: %s", qPrintable(doc.toJson(QJsonDocument::Indented)));

    JsonResponse resp(doc.object());
    socketManager_.getInfo()->setStatus(resp.getError().getErrorString());
    disconnect(&socketManager_, &WebSocketManager::dataReceived,
               this, &Registration::processRegistrationResponse);
}
