#ifndef AUTHORIZATION_H
#define AUTHORIZATION_H

#include <QQmlApplicationEngine>

#include "login.h"
#include "registration.h"
#include "info.h"

/* this is a class that depends on used engine. It is tied up on engine load functions */
class Authorization : public QObject {
    Q_OBJECT

public:
    Authorization();

public slots:
    void onRegistrationButtonClicked();

private:
    Registration *reg_;
    Login *login_;
    QQmlApplicationEngine engine_;
    Info *info_;
};

#endif // AUTHORIZATION_H
