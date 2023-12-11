//
// Created by Nanomoa on 23-12-11.
//

#ifndef MARKDOWNEDITOR_MAINMODEL_H
#define MARKDOWNEDITOR_MAINMODEL_H

#include <QObject>
#include "MainController.h"

class MainModel : public QObject
{
Q_OBJECT
public:
    explicit MainModel(QObject* parent = nullptr) : QObject(parent) { }

public slots:
    Q_INVOKABLE QString toHtml(const QString& mdText)
    {
        controller.setMarkdownContent(mdText);
        controller.parserMdToHtml();
        return controller.getHtmlContent();
    }

private:
    MainController controller;
};

#endif //MARKDOWNEDITOR_MAINMODEL_H
