//
// Created by Nanomoa on 23-11-3.
//

#ifndef MARKDOWN_PARSER_MARKDOWN_H
#define MARKDOWN_PARSER_MARKDOWN_H

#include "AbstractMarkdown.h"


namespace Markdown
{

    class MarkdownP : public AbstractMarkdown
    {
    private:
        /**UPDATE: 为了支持嵌套列表，将状态改成了状态栈，用于存储前面的"深度值"，即前面连续多行开头的空白字符数目，
         * 根据栈顶可以分析出当前行是否深入一层嵌套还是从深层列表中出去**/
        std::stack<int> ul_level;
        std::stack<int> ol_level;

        /**UPDATE: 为了支持嵌套blockquote，将状态改成数值，表示该行处于多少层的blockquote中**/
        int blockquote_level;

        /**
         * @name regex_handler
         * @brief 处理行元素的正则处理器，元素为markdown_regex_expression(std::pair)，第一个元素为匹配用的正则表达式，第二个元素为处理函数
         * **/
        std::vector<markdown_regex_expression> regex_handler;

        /**
         * @name regex_handler_block
         * @brief 处理块元素的正则处理器，元素为markdown_regex_expression(std::pair)，第一个元素为匹配用的正则表达式，第二个元素为处理函数
         * **/
        std::vector<markdown_regex_expression> regex_handler_block;


    protected:
        parse_result parseHeadline(const std::string &line, const std::regex &reg) override;

        parse_result parseCode(const std::string &line, const std::regex &reg) override;

        parse_result parseInlineCode(const std::string &line, const std::regex &reg) override;

        parse_result parseHr(const std::string &line, const std::regex &reg) override;

        parse_result parseBulletList(const std::string &line, const std::regex &reg) override;

        parse_result parseNumberedList(const std::string &line, const std::regex &reg) override;

        parse_result parseBold(const std::string &line, const std::regex &reg) override;

        parse_result parseItalic(const std::string &line, const std::regex &reg) override;

        parse_result parseLink(const std::string &line, const std::regex &reg) override;

        parse_result parseTable(const std::string &line, const std::regex &reg) override;

        parse_result parseImage(const std::string &line, const std::regex &reg) override;

        parse_result parseBlockquoting(const std::string &line, const std::regex &reg) override;

        parse_result parseDel(const std::string &line, const std::regex &reg) override;

        /**
         * @name parseLine
         * @brief 读取一行数据并解析该行的数据，转化成html格式的代码
         * @param line 一行数据
         * @return std::string 该行数据解析后的html代码，注意此时已经可能不止一行了
         * **/
        std::string parseLine(std::string line);

        /**
         * @name parseBlock
         * @brief 读取整篇文档，解析匹配到特定格式的块(表格、代码)，将该块转化成html格式的代码
         * @param text 全文
         * @return std::string 转化后的全文，局部是html代码
         * **/
        std::string parseBlock(std::string text);

    public:
        MarkdownP();

        std::string parse(std::string text) override;

    };
}

#endif //MARKDOWN_PARSER_MARKDOWN_H
