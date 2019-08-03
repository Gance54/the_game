#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QDebug>

#include "game.h"
#include "login.h"

int main(int argc, char *argv[]) {
    QGuiApplication app(argc, argv);
    Login login;

    /* Class registration fron login.h */
    qmlRegisterType<Login>("io.qt.services.login", 1, 1, "LogInClass");


    const QUrl url(QStringLiteral("qrc:/qml/login.qml"));
    QQmlApplicationEngine engine;

    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [&engine, &login] () {

        QObject *rootObject = engine.rootObjects().first();
        QObject *qmlObject = rootObject->findChild<QObject*>("LoginButtonObject");

        if(qmlObject) {
            QObject::connect(qmlObject, SIGNAL(qmlSignalPressed(QString, QString)),
                                 &login, SLOT(onButtonClicked(QString, QString)));

        }

    });

    engine.load(url);

    return app.exec();
}
