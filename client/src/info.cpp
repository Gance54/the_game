#include "info.h"


Info::Info(QObject *parent) :
    QObject(parent) {
    status_ = "Welcome!";
}

QString Info::getVersion() {
    return version_.getVersionString();
}

QString Info::getStatus() {
    return status_;
}

void Info::setStatus(QString status) {
    if (status == status_)
        return;

    status_ = status;
    emit statusChanged();
}

void Info::onStatusChanged(const QString status) {
    setStatus(status);
}

