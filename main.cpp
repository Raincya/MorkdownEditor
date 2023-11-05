#include <QApplication>
#include <QPushButton>
#include <QtQuick/QQuickView>
#include <QQmlApplicationEngine>

int main(int argc, char *argv[])
{
    std::unique_ptr<QGuiApplication> app(new QGuiApplication(argc, argv));

    std::unique_ptr<QQuickView> view(new QQuickView());
    view->setResizeMode(QQuickView::SizeRootObjectToView);
    view->setSource(QUrl::fromLocalFile("../Pages/LoginAndRegister/View.qml"));
    view->show();

    return app->exec();
}