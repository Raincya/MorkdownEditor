//
// Created by Nanomoa on 23-12-9.
//

#ifndef MARKDOWNEDITOR_LOGINANDREGMODEL_H
#define MARKDOWNEDITOR_LOGINANDREGMODEL_H

#include <QObject>
#include "../../Utils/Json/json.hpp"
#include "LoginAndRegController.h"

class LoginAndRegModel : public QObject
{
Q_OBJECT
public:
    explicit LoginAndRegModel(QObject* parent = nullptr) : QObject(parent) { }

public slots:
    Q_INVOKABLE QString login(const QString& username, const QString& password)
    {
        configor::json::value res = controller.Login(username, password);
        return QString::fromStdString(res["msg"]);
    }

    Q_INVOKABLE QString reg(const QString& username, const QString& password)
    {
        configor::json::value res = controller.Reg(username, password);
        return QString::fromStdString(res["msg"]);
    }
private:
    LoginAndRegController controller;
};

#endif //MARKDOWNEDITOR_LOGINANDREGMODEL_H
