//
// Created by Nanomoa on 23-11-3.
//

#include <sstream>
#include "Parser.h"
#include "Common.h"
#include "../StringUtil/StringUtil.h"

namespace Markdown
{
    parse_result Parser::parseString(const std::string &content)
    {
        parse_result ret = _md->parse(content);
        std::string style;
        if(_decorator)
        {
            style = _decorator->decorate();
        } else
        {
            // 如果装饰器指针为空，style块可以用空字符串来表示
            style = "";
        }
        ret = addHtmlTag(ret, style);
        return ret;
    }

    parse_result Parser::parseFile(const std::string &filename)
    {
        auto ret = readFileAll("test.md");
        ret = _md->parse(ret);
        std::string style;
        if(_decorator)
        {
            style = _decorator->decorate();
        } else
        {
            // 如果装饰器指针为空，style块可以用空字符串；来表示
            style = "";
        }
        ret = addHtmlTag(ret, style);
        return ret;
    }

    std::string Parser::addHtmlTag(const std::string &content, const std::string &style)
    {
        std::stringstream ss;
        ss << "<!DOCTYPE html>\n"
              "<html>\n"
              "<head>\n"
              "<meta charset=\""
           << _get("charset")
           << "\">\n"
              "<title></title>\n"
              "</head>\n"
              "<body class=\"markdown-body\">\n"
           << content
           << "</body>\n"
              "<style>"
           << style
           << "</style>"
              "</html>";
        return ss.str();
    }
}
