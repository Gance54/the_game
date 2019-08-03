#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QDebug>
#include "login.h"

#include <QtQuick>
#include <QApplication>

/*int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    Login login;

    qmlRegisterType<Login>("io.qt.services.login", 1, 1, "LogInClass");

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    const QUrl url(QStringLiteral("qrc:/qml/login.qml"));

    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);


    engine.load(url);

    QObject::connect(&engine, SIGNAL(qmlSignalPressed(QString, QString)),
                         &login, SLOT(cppSlot(QString, QString)));

    return app.exec();
}*/

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    Login login;

    qmlRegisterType<Login>("io.qt.services.login", 1, 1, "LogInClass");


    const QUrl url(QStringLiteral("qrc:/qml/login.qml"));
    QQmlApplicationEngine engine;

    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [&engine, &login] () {

        QObject *rootObject = engine.rootObjects().first();
        QObject *qmlObject = rootObject->findChild<QObject*>("LoginButtonObject");

        if(qmlObject)
            QObject::connect(qmlObject, SIGNAL(qmlSignalPressed(QString, QString)),
                                 &login, SLOT(onButtonClicked(QString, QString)));
    });

    engine.load(url);

    return app.exec();
}
