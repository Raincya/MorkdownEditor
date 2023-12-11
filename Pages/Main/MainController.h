//
// Created by Nanomoa on 23-12-11.
//

#ifndef MARKDOWNEDITOR_MAINCONTROLLER_H
#define MARKDOWNEDITOR_MAINCONTROLLER_H

#include <QString>
#include "../../Utils/MarkdownParser/Markdown.h"
#include "../../Utils/MarkdownParser/CssDecorator.h"
#include "../../Utils/MarkdownParser/Parser.h"

class MainController
{
public:
    MainController() = default;

    void setMarkdownContent(const QString& text)
    {
        this->markdownContent = text;
    }

    void setHtmlContent(const QString& text)
    {
        this->htmlContent = text;
    }

    QString getMarkdownContent()
    {
        return this->markdownContent;
    }

    QString getHtmlContent()
    {
        return this->htmlContent;
    }

    void parserMdToHtml()
    {
        Markdown::MarkdownP md;
        Markdown::CssDecorator cssDecorator("../Src/preview/preview.css");

        Markdown::Parser parser(&md, &cssDecorator);

        std::string htmlRes = parser.parseString(this->getMarkdownContent().toStdString());
        this->setHtmlContent(QString::fromStdString(htmlRes));
    }

private:
    QString markdownContent;
    QString htmlContent;
};

#endif //MARKDOWNEDITOR_MAINCONTROLLER_H
