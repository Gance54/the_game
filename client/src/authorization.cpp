#include <QQmlContext>

#include "authorization.h"

Authorization::Authorization() {
    info_ = new Info();
    login_ = new Login();
    engine_.rootContext()->setContextProperty("InfoObject", info_);
    engine_.rootContext()->setContextProperty("LoginObject", login_);

    const QUrl url(QStringLiteral("qrc:/qml/Authorization.qml"));
    engine_.load(url);

    QObject *rootObject = engine_.rootObjects().first();
    QObject *loginObject = rootObject->findChild<QObject*>("LoginButtonObject");

    if (loginObject) {
        QObject::connect(loginObject, SIGNAL(qmlSignalPressed(QString, QString)),
                             login_, SLOT(onLoginButtonClicked(QString, QString)));
    }

    QObject *regObject = rootObject->findChild<QObject*>("RegisterButtonObject");

    if (regObject) {
        QObject::connect(regObject, SIGNAL(qmlSignalPressed()),
                         this, SLOT(onRegistrationButtonClicked()));
    }
}

void Authorization::onRegistrationButtonClicked() {

    reg_ = new Registration();
}
