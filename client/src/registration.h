#ifndef REGISTER_H
#define REGISTER_H

#include <QObject>
#include <QString>
#include <QDebug>
#include "game.h"

class Registration : public QObject
{
    Q_OBJECT

public:
    explicit Registration(QObject *parent = nullptr);

public slots:
    void onRegisterButtonClicked();

};

#endif // REGISTER_H
