//
// Created by Nanomoa on 23-12-9.
//

#ifndef MARKDOWNEDITOR_LOGINANDREGMODEL_H
#define MARKDOWNEDITOR_LOGINANDREGMODEL_H

#include <QObject>
#include "LoginAndRegController.h"

class LoginAndRegModel : public QObject
{
Q_OBJECT
public:
    explicit LoginAndRegModel(QObject* parent = nullptr) : QObject(parent) { }

public slots:
    void login(QString& username, QString& password)
    {
        controller->Login(username.toStdString(), password.toStdString());
    }

private:
    std::unique_ptr<LoginAndRegController> controller;
};

#endif //MARKDOWNEDITOR_LOGINANDREGMODEL_H
