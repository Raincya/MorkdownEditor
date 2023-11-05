//
// Created by Nanomoa on 23-11-3.
//

#ifndef MARKDOWN_PARSER_MARKDOWN_PARSER_H
#define MARKDOWN_PARSER_MARKDOWN_PARSER_H

#include "Common.h"
#include "AbstractMarkdown.h"
#include "AbstractDecorator.h"
#include "AbsractParser.h"
#include "Configurable.h"

namespace Markdown
{
    class Parser : AbstractParser, Configurable
    {
    private:
        AbstractMarkdown *_md;  //Markdown 解释器
        AbstractDecorator *_decorator; //装饰器

        /**
         * @brief 内部函数，加上html标签<html><head>...</head><body>...</body></html>，使之成为符合规范的html文档
         * **/
        std::string addHtmlTag(const std::string &content, const std::string &style);

    public:
        Parser(AbstractMarkdown *md, AbstractDecorator *decorator) : _md{md}, _decorator(decorator) { }

        Parser(AbstractMarkdown *md, AbstractDecorator *decorator, const setting_type &settings) : Configurable(settings), _md(md), _decorator(decorator) {}

        /**
         * @brief 解析字符串，返回html格式
         * @param content md格式的字符串
         * @return html格式的字符串
         * **/
        parse_result parseString(const std::string &content) override;

        /**
         * @brief 给定一个文件，解析其字符串并返回html格式
         * @param filename 文件名
         * @return html格式的字符串
         *
         * **/
        parse_result parseFile(const std::string &filename) override;

        ~Parser() override = default; //todo 虚继承的析构
    };
}

#endif //MARKDOWN_PARSER_MARKDOWN_PARSER_H
