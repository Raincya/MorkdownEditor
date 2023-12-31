//
// Created by Nanomoa on 23-11-3.
//

#ifndef MARKDOWN_PARSER_CONFIGURED_DECORATOR_H
#define MARKDOWN_PARSER_CONFIGURED_DECORATOR_H

#include "AbstractDecorator.h"
#include "Configurable.h"

namespace Markdown
{
    /**
     * @brief ConfiguredDecorator 类，接受一个配置，并根据配置渲染出特定的style样式
     * @details 需要继承两个类：抽象类AbstractDecorator以及配置类Configurable
     * **/
    class ConfiguredDecorator : public AbstractDecorator, Configurable
    {
    public:
        ConfiguredDecorator() = default;

        explicit ConfiguredDecorator(const setting_type& settings) : Configurable(settings) { }

        std::string decorate() override;
    };
}

#endif //MARKDOWN_PARSER_CONFIGURED_DECORATOR_H
