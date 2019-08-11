#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QDebug>

#include "game.h"
#include "login.h"
#include "registration.h"
#include "info.h"
#include "authorization.h"

int main(int argc, char *argv[]) {
    QGuiApplication app(argc, argv);

    Authorization *auth = new Authorization();

    return app.exec();
}
