#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QDebug>

#include "game.h"
#include "login.h"

int main(int argc, char *argv[]) {
    QGuiApplication app(argc, argv);
    Login login;

    const QUrl url(QStringLiteral("qrc:/qml/login.qml"));
    QQmlApplicationEngine engine;


    /* Register object of Login class (login.h) as loginClass in QML */
    engine.rootContext()->setContextProperty("loginObject", &login);

    engine.load(url);

    qDebug() << engine.rootObjects().count();

    /*QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [&engine, &login] () {*/

    QObject *rootObject = engine.rootObjects().first();
    QObject *qmlObject = rootObject->findChild<QObject*>("LoginButtonObject");

    if(qmlObject) {
        QObject::connect(qmlObject, SIGNAL(qmlSignalPressed(QString, QString)),
                             &login, SLOT(onLoginButtonClicked(QString, QString)));

        }
    //});

    return app.exec();
}
