#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QDebug>

#include "game.h"
#include "login.h"
#include "registration.h"
#include "info.h"

int main(int argc, char *argv[]) {
    QGuiApplication app(argc, argv);
    Login login;
    Registration reg;
    Info info;

    const QUrl url(QStringLiteral("qrc:/qml/login.qml"));
    QQmlApplicationEngine engine;

    /* Registration object of Login class (login.h) as loginClass in QML */
    engine.rootContext()->setContextProperty("InfoObject", &info);
    engine.rootContext()->setContextProperty("LoginObject", &login);

    engine.load(url);

    QObject *rootObject = engine.rootObjects().first();
    QObject *loginObject = rootObject->findChild<QObject*>("LoginButtonObject");
    QObject *regObject = rootObject->findChild<QObject*>("RegisterButtonObject");


    if (loginObject) {
        QObject::connect(loginObject, SIGNAL(qmlSignalPressed(QString, QString)),
                             &login, SLOT(onLoginButtonClicked(QString, QString)));
        }

    if (regObject) {
        QObject::connect(regObject, SIGNAL(qmlSignalPressed()),
                             &reg, SLOT(onRegisterButtonClicked()));
        }

    return app.exec();
}
