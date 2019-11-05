#ifndef INFO_H
#define INFO_H

#include <QObject>
#include <QString>
#include <QDebug>
#include "game.h"

class Info : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString version READ getVersion)
    Q_PROPERTY(QString status READ getStatus WRITE setStatus NOTIFY statusChanged)

public:
    explicit Info(QObject *parent = nullptr);
    QString getVersion();
    QString getStatus();
    QString getErrLogin();

    void setStatus(QString status);
    void setErrLogin(QString errLogin);

signals:
    void statusChanged();
    void errLoginOccured();

public slots:
    void onStatusChanged(const QString status);
    void onErrLogin(const QString errLogin);

private:
    QString status_;
    QString errLogin_;
    Version version_;
};

#endif // INFO_H
