//
// Created by Nanomoa on 23-12-9.
//

#ifndef MARKDOWNEDITOR_CONTROLLER_H
#define MARKDOWNEDITOR_CONTROLLER_H

#include <utility>

#include "../../Utils/Json/json.hpp"
#include "../../Utils/HttpClient/HttpClient.h"
#include "../../Config/ServerConfig.h"

struct Status
{
    bool isSuccess{};
    std::string message;
    Status() = default;
    Status(const bool _isSuccess, std::string  _message) : isSuccess(_isSuccess), message(std::move(_message)) { }
};

class LoginAndRegController
{
public:
    Status Login(const std::string& username, const std::string& password)
    {
        this->userInfo = configor::json::object{
                {"username", username},
                {"password", password}
        };

        std::unique_ptr<HttpClient> httpClient = std::make_unique<HttpClient>(QString::fromStdString((new ServerConfig())->login()));

        Status result;

        httpClient->json(QString::fromStdString(configor::json::dump(this->userInfo)))
                .success([&](const QString& req) -> void
                         {
                             configor::json::value jsonReq = configor::json::parse(req.toStdString());
                             result = {
                                     jsonReq["code"] == 1,
                                     jsonReq["msg"]
                             };
                         })
                .fail([&](const QString& req, int code) -> void
                      {
                          result = {
                                  false,
                                  req.toStdString()
                          };
                      })
                .post();

        return result;
    }

    Status Reg(const std::string& username, const std::string& password)
    {
        this->userInfo = configor::json::object{
                {"username", username},
                {"password", password}
        };

        std::unique_ptr<HttpClient> httpClient = std::make_unique<HttpClient>(QString::fromStdString((new ServerConfig())->reg()));

        Status result;

        httpClient->json(QString::fromStdString(configor::json::dump(this->userInfo)))
                .success([&](const QString& req) -> void
                         {
                             configor::json::value jsonReq = configor::json::parse(req.toStdString());
                             result = {
                                     jsonReq["code"] == 1,
                                     jsonReq["msg"]
                             };
                         })
                .fail([&](const QString& req, int code) -> void
                      {
                          result = {
                                  false,
                                  req.toStdString()
                          };
                      })
                .post();

        return result;
    }
private:
    configor::json::value userInfo;
};

#endif //MARKDOWNEDITOR_CONTROLLER_H
