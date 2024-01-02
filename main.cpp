#include <QApplication>
#include <QPushButton>
#include <QtQuick/QQuickView>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "Pages/LoginAndRegister/LoginAndRegModel.h"
#include "Pages/Main/MainModel.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
    std::unique_ptr<QQmlApplicationEngine> engine = std::make_unique<QQmlApplicationEngine>();

    MainModel mainModel;
    LoginAndRegModel loginAndRegModel;
    engine->rootContext()->setContextProperty("main", &mainModel);
    engine->rootContext()->setContextProperty("loginAndReg", &loginAndRegModel);
    engine->rootContext()->setContextProperty("app", &app);

    const QUrl startUrl("../Pages/LoginAndRegister/View.qml");
    engine->load(startUrl);

    return QGuiApplication::exec();
}