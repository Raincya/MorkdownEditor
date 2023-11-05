//
// Created by Nanomoa on 23-11-3.
//

#ifndef MARKDOWN_PARSER_ABSRACT_PARSER_H
#define MARKDOWN_PARSER_ABSRACT_PARSER_H

#include "Common.h"

namespace Markdown
{
    /**
     * @brief 解析器的抽象类
     * **/
    class AbstractParser
    {
    public:
        AbstractParser() = default;

        /**
         * @brief 解析字符串，返回html格式
         * @param content md格式的字符串
         * @return html格式的字符串
         * **/
        virtual parse_result parseString(const std::string &content) = 0;

        /**
         * @brief 给定一个文件，解析其字符串并返回html格式
         * @param filename 文件名
         * @return html格式的字符串
         *
         * **/
        virtual parse_result parseFile(const std::string &filename) = 0;
    };
}
#endif //MARKDOWN_PARSER_ABSRACT_PARSER_H
