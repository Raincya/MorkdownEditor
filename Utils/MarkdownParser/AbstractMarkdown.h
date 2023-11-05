//
// Created by Nanomoa on 23-11-3.
//

#ifndef MARKDOWN_PARSER_ABSTRACT_MARKDOWN_H
#define MARKDOWN_PARSER_ABSTRACT_MARKDOWN_H

#include <string>
#include <regex>
#include "Common.h"

namespace Markdown
{
    /***
     * 抽象类 AbstractMarkdown
     * 提供多个抽象函数，用于解析字符串并转成html文档格式，函数需要由子类来实现
     * todo 一般用法：具体实现函数放在private域内，暴露接口用于接受字符串并能自动选择相应的函数进行处理
     * ***/
    class AbstractMarkdown
    {
    protected:

        /*************************
         * @name parseHeadline
         * @brief 解析标题
         * @param 传入匹配后的字符串
         * **********************/
        virtual parse_result parseHeadline(const std::string &line, const std::regex &reg) = 0;

        /*************************
         * @name parseCode
         * @brief 解析代码
         * @param 传入匹配后的字符串
         * **********************/
        virtual parse_result parseCode(const std::string &line, const std::regex &reg) = 0;

        /*************************
         * @name parseCode
         * @brief 解析内联代码
         * @param 传入匹配后的字符串
         * **********************/
        virtual parse_result parseInlineCode(const std::string &line, const std::regex &reg) = 0;

        /*************************
         * @name parseHr
         * @brief 解析分隔符
         * @param 传入匹配后的字符串
         * **********************/
        virtual parse_result parseHr(const std::string &line, const std::regex &reg) = 0;

        /*************************
         * @name parseBulletList
         * @brief 解析无序列表
         * @param 传入匹配后的字符串
         * **********************/
        virtual parse_result parseBulletList(const std::string &line, const std::regex &reg) = 0;

        /*************************
         * @name parseNumberedList
         * @brief 解析有序列表
         * @param 传入匹配后的字符串
         * **********************/
        virtual parse_result parseNumberedList(const std::string &line, const std::regex &reg) = 0;

        /*************************
         * @name parse_bolditalic
         * @brief 解析加粗文字
         * @param 传入匹配后的字符串
         * **********************/
        virtual parse_result parseBold(const std::string &line, const std::regex &reg) = 0;

        /*************************
         * @name parseItalic
         * @brief 解析斜体文字
         * @param 传入匹配后的字符串
         * **********************/
        virtual parse_result parseItalic(const std::string &line, const std::regex &reg) = 0;

        /*************************
         * @name parseLink
         * @brief 解析链接
         * @param 传入匹配后的字符串
         * **********************/
        virtual parse_result parseLink(const std::string &line, const std::regex &reg) = 0;

        /*************************
         * @name parseTable
         * @brief 解析表格
         * @param 传入匹配后的字符串
         * **********************/
        virtual parse_result parseTable(const std::string &line, const std::regex &reg) = 0;

        /*************************
         * @name parseImage
         * @brief 解析图像
         * @param 传入匹配后的字符串
         * **********************/
        virtual parse_result parseImage(const std::string &line, const std::regex &reg) = 0;

        /*************************
         * @name parseDel
         * @brief 解析删除
         * @param 传入匹配后的字符串
         * **********************/
        virtual parse_result parseDel(const std::string &line, const std::regex &reg) = 0;

        /*************************
         * @name parseBlockquoting
         * @brief 解析块内引用
         * @param 传入匹配后的字符串
         * **********************/
        virtual parse_result parseBlockquoting(const std::string &line, const std::regex &reg) = 0;

        /****
         * 下面是每一个Markdown格式对应的正则表达式pattern
         * 需要子类进行定义
         * ****/
        /**处理标题的正则表达式pattern**/
        std::regex headline_pattern;
        /**处理粗体的正则表达式pattern**/
        std::regex bold_pattern;
        /**处理斜体的正则表达式pattern**/
        std::regex italic_pattern;
        /**处理删除线的正则表达式pattern**/
        std::regex del_pattern;
        /**处理分隔符的正则表达式pattern**/
        std::regex hr_pattern;
        /**处理无序列表项的正则表达式pattern**/
        std::regex ul_li_pattern;
        /**处理有序列表项的正则表达式pattern**/
        std::regex ol_li_pattern;
        /**处理链接的正则表达式pattern**/
        std::regex link_pattern;
        /**处理图片的正则表达式pattern**/
        std::regex img_pattern;
        /**处理代码块的正则表达式pattern**/
        std::regex code_pattern;
        /**处理内联代码的正则表达式pattern**/
        std::regex inline_code_pattern;
        /**处理块引用的正则表达式pattern**/
        std::regex blockquoting_pattern;
        /**处理表格的正则表达式pattern**/
        std::regex table_pattern;

    public:
        AbstractMarkdown() = default;

        /*************************
         * @name parse
         * @brief 接受数据，并返回html的格式
         * @param line 数据
         * @return std::string html格式的数据
         * **********************/
        virtual std::string parse(std::string text) = 0;
    };
}


#endif //MARKDOWN_PARSER_ABSTRACT_MARKDOWN_H
