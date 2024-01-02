//
// Created by Nanomoa on 23-12-9.
//

#ifndef MARKDOWNEDITOR_LOGINANDREGCONTROLLER_H
#define MARKDOWNEDITOR_LOGINANDREGCONTROLLER_H

#include <utility>
#include <iostream>
#include <QGuiApplication>
#include <thread>

#include "../../Utils/Json/json.hpp"
#include "../../Utils/HttpClient/HttpClient.h"
#include "../../Config/ServerConfig.h"

class LoginAndRegController
{
public:
    configor::json::value Login(const QString& username, const QString& password)
    {
        this->userInfo = configor::json::object{
                {"username", username.toStdString()},
                {"password", password.toStdString()}
        };


        std::unique_ptr<httplib::Client> client = std::make_unique<httplib::Client>("http://localhost:4561");

        auto res_from_server = client->Post("/user/login",
                                            {
                                                    {"content-type", "application/json"}
                                            },
                                            configor::json::dump(this->userInfo),
                                            "application/json");

        configor::json::value result = configor::json::parse(res_from_server->body);

        std::cerr << configor::json::dump(result) << std::endl;

        return result;
    }

    configor::json::value Reg(const QString& username, const QString& password)
    {
        this->userInfo = configor::json::object{
                {"username", username.toStdString()},
                {"password", password.toStdString()}
        };


        std::unique_ptr<httplib::Client> client = std::make_unique<httplib::Client>("http://localhost:4561");

        auto res_from_server = client->Post("/user/reg",
                                            {
                                                    {"content-type", "application/json"}
                                            },
                                            configor::json::dump(this->userInfo),
                                            "application/json");

        configor::json::value result = configor::json::parse(res_from_server->body);

        std::cerr << configor::json::dump(result) << std::endl;

        return result;
    }
private:
    configor::json::value userInfo;
};

#endif //MARKDOWNEDITOR_LOGINANDREGCONTROLLER_H
