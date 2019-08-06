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
    QObject *infoObject = rootObject->findChild<QObject*>("InfoObject");
    QObject *loginObject = rootObject->findChild<QObject*>("LoginButtonObject");
    QObject *regObject = rootObject->findChild<QObject*>("RegisterButtonObject");

    if (infoObject) {
        QObject::connect(infoObject, SIGNAL(qmlSignalStatusChanged(QString)),
                             &info, SLOT(onStatusChanged(QString)));
        }

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



/*QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                 &app, [&engine, &login] () {*/    //});
