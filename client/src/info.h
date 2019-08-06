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
    Q_PROPERTY(QString status READ getStatus NOTIFY statusChanged)

public:
    explicit Info(QObject *parent = nullptr);
    QString getVersion();
    QString getStatus();

    void setStatus(QString status);

signals:
    void statusChanged();

public slots:
    void onStatusChanged(const QString status);

private:
    QString status_;
    Version version_;
};

#endif // INFO_H
