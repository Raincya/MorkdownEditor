#include <QApplication>
#include <QPushButton>
#include <QtQuick/QQuickView>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "Pages/LoginAndRegister/LoginAndRegModel.h"
#include "Pages/Main/MainModel.h"

int main(int argc, char *argv[])
{
    std::unique_ptr<QGuiApplication> app = std::make_unique<QGuiApplication>(argc, argv);

    std::unique_ptr<QQmlApplicationEngine> engine = std::make_unique<QQmlApplicationEngine>();


    MainModel mainModel;

    engine->rootContext()->setContextProperty("main", &mainModel);

    const QUrl startUrl("../Pages/Main/View.qml");
    engine->load(startUrl);

    return app->exec();
}