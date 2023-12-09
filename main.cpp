#include <QApplication>
#include <QPushButton>
#include <QtQuick/QQuickView>
#include <QQmlApplicationEngine>
#include "Pages/LoginAndRegister/Model.h"

// 注册qml模块
void RegisterQmlType()
{
    qmlRegisterType<LoginAndRegModel>("LoginAndReg", 1, 0, "LoginAndRegModel");

}

int main(int argc, char *argv[])
{
    std::unique_ptr<QGuiApplication> app(new QGuiApplication(argc, argv));

    RegisterQmlType();

    std::unique_ptr<QQmlApplicationEngine> engine = std::make_unique<QQmlApplicationEngine>();
    const QUrl startUrl("../Pages/LoginAndRegister/View.qml");
    engine->load(startUrl);

    return app->exec();
}