//
// Created by Nanomoa on 23-12-9.
//

#ifndef MARKDOWNEDITOR_MODEL_H
#define MARKDOWNEDITOR_MODEL_H

#include <QObject>
#include "Controller.h"

class LoginAndRegModel : public QObject
{
Q_OBJECT
public:
    explicit LoginAndRegModel(QObject* parent = nullptr) : QObject(parent) { }

    Q_INVOKABLE void login(QString& username, QString& password)
    {
        controller->Login(username.toStdString(), password.toStdString());
    }

private:
    std::unique_ptr<LoginAndRegController> controller;
};

#endif //MARKDOWNEDITOR_MODEL_H
