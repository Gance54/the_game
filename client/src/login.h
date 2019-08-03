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

public:
    explicit Login(QObject *parent = nullptr);
    void setLogin(const QString &login);
    void setPassword(const QString &password);
    QString getLogin();
    QString getPassword();
    QString getVersion();

public slots:
    void onButtonClicked(const QString &login, const QString &pwd);

signals:
    void LoginButtonClicked();

private:
    QString login_;
    QString password_;
    Version version_;
};

#endif // LOGIN_H
