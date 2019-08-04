#ifndef LOGIN_H
#define LOGIN_H

#include <QObject>
#include <QString>
#include <QDebug>
#include "game.h"

class Login : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString login READ getLogin WRITE setLogin)
    Q_PROPERTY(QString password READ getPassword WRITE setPassword)
    Q_PROPERTY(QString version READ getVersion)
    Q_PROPERTY(QString status READ getStatus NOTIFY statusChanged)

public:
    explicit Login(QObject *parent = nullptr);
    void setLogin(const QString &login);
    void setPassword(const QString &password);
    QString getLogin();
    QString getPassword();
    QString getVersion();
    QString getStatus();

    void setStatus(QString status);

signals:
    void statusChanged();

public slots:
    void onLoginButtonClicked(const QString &login, const QString &pwd);

private:
    QString login_;
    QString password_;
    QString status_;
    Version version_;
};

#endif // LOGIN_H
