//
// Created by Nanomoa on 23-11-3.
//

#ifndef MARKDOWN_PARSER_CSS_DECORATOR_H
#define MARKDOWN_PARSER_CSS_DECORATOR_H

#include <utility>

#include "AbstractDecorator.h"

namespace Markdown
{
    /**
     * @brief CssDecorator 类，接受一个CSS文件路径，并根据CSS文件渲染出特定的style样式
     * @details 需要继承两个类：抽象类AbstractDecorator以及配置类Configurable
     * **/
    class CssDecorator : public AbstractDecorator
    {
    protected:
        std::string _css_filename;

    public:
        CssDecorator() = default;

        explicit CssDecorator(std::string css_filename) : _css_filename(std::move(css_filename)) { }

        std::string decorate() override;
    };
}
#endif //MARKDOWN_PARSER_CSS_DECORATOR_H
