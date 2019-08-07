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

public:
    explicit Login(QObject *parent = nullptr);
    void setLogin(const QString &login);
    void setPassword(const QString &password);
    QString getLogin();
    QString getPassword();

public slots:
    void onLoginButtonClicked(const QString &login, const QString &pwd);

private:
    QString login_;
    QString password_;
};

#endif // LOGIN_H
