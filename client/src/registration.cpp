#include "registration.h"

Registration::Registration(QObject *parent) :
    QObject(parent) {
}

void Registration::onRegisterButtonClicked() {
   qDebug() << "Registration clicked";
}
