//
// Created by Nanomoa on 23-11-3.
//

#include <iostream>
#include <string>
#include <sstream>
#include "Markdown.h"
#include "Common.h"
#include "../StringUtil/StringUtil.h"


namespace Markdown
{

    parse_result MarkdownP::parseHeadline(const std::string &line, const std::regex &reg)
    {
        std::smatch m;
        std::regex_match(line, m, reg);
        int h_level = static_cast<int>(m[1].str().length()); // 根据#号多少生成几级标题
        h_level = (h_level <= 6 ? h_level : 6);
        std::string content = m[2].str();
        std::stringstream ret;
        ret << "<h" << h_level << ">" << content << "</h" << h_level << ">";
        return ret.str();
    }

    parse_result MarkdownP::parseCode(const std::string &line, const std::regex &reg)
    {
        return regex_replace(line, reg, "<code>\n$1</code>\n");
    }

    parse_result MarkdownP::parseInlineCode(const std::string &line, const std::regex &reg)
    {
        return regex_replace(line, reg, "<code>$1</code>");
    }

    parse_result MarkdownP::parseHr(const std::string &line, const std::regex &reg)
    {
        return "<hr>";
    }

    parse_result MarkdownP::parseBulletList(const std::string &line, const std::regex &reg)
    {
        return regex_replace(line, reg, "<li>$2</li>"); // 直接替代成<li>...</li>
    }

    parse_result MarkdownP::parseNumberedList(const std::string &line, const std::regex &reg)
    {
        return regex_replace(line, reg, "<li>$2</li>"); // 直接替代成<li>...</li>
    }

    parse_result MarkdownP::parseBold(const std::string &line, const std::regex &reg)
    {
        return regex_replace(line, reg, "<strong>$2</strong>"); // 直接替代成<strong>...</strong>
    }

    parse_result MarkdownP::parseItalic(const std::string &line, const std::regex &reg)
    {
        return regex_replace(line, reg, "<em>$2</em>"); // 直接替代成<em>...</em>
    }

    parse_result MarkdownP::parseLink(const std::string &line, const std::regex &reg)
    {
        return regex_replace(line, reg, "<a href=\"$2\">$1</a>");
    }

    parse_result MarkdownP::parseTable(const std::string &line, const std::regex &reg)
    {
        std::smatch m;
        std::regex_search(line, m, reg);
        std::string head = m[1].str(); // 获取表格首行
        trim(head);
        std::vector<std::string> head_cols = splitStr(head, "|");
        int col_num = static_cast<int>(head_cols.size()); //总列数
        std::string content = m[3].str();  //注意匹配后所有body的信息全部在一个字符串中
        trim(content); //trim后最后一个换行符去掉了，所以后面要+1
        auto all_cols = splitStr(content, "|"); //切割出内容行的所有列，
        int content_row_num = static_cast<int>((all_cols.size() + 1) / (col_num + 1));
        std::string content_arr[content_row_num][col_num];
        for(int i = 0, row = 0;i < all_cols.size();i += (col_num + 1), row++)
        {
            for(int j = 0;j < col_num;j++)
            {
                content_arr[row][j] = all_cols[i + j];
            }
        }

        std::stringstream ret;
        ret << "<table>\n<thead>\n<tr>\n";
        for(const auto &head_col : head_cols)
        {
            ret << "<th>" << head_col << "</th>\n";
        }
        ret << "</tr>\n</thead>\n<tbody>\n";

        for(int i = 0;i < content_row_num;i++)
        {
            ret << "<tr>\n";
            for(int j = 0;j < col_num;j++)
            {
                ret << "<td>" << content_arr[i][j] << "</td>\n";
            }
            ret << "</tr>\n";
        }
        ret << "</tbody>\n</table>\n";

        return m.prefix().str() + ret.str() + m.suffix().str();
    }

    parse_result MarkdownP::parseImage(const std::string &line, const std::regex &reg)
    {
        return regex_replace(line, reg, R"(<img src="$2" alt="$1">)");
    }

    parse_result MarkdownP::parseBlockquoting(const std::string &line, const std::regex &reg)
    {
        return regex_replace(line, reg, "$2");
    }

    parse_result MarkdownP::parseDel(const std::string &line, const std::regex &reg)
    {
        return regex_replace(line, reg, "<del>$2</del>"); // 直接替代成<del>...</del>
    }

    MarkdownP::MarkdownP()
    {
        using namespace std::placeholders;
        /**处理标题的正则表达式，**/
        /**FIXED: 需要考虑到标题中可能存在井号, std::regex("^(#{1,6})([^#\n]+)$")不太适用**/
        headline_pattern = std::regex("^(#{1,6})([^\n]+)$");  // headline 标题的pattern
        bold_pattern = std::regex(R"((\*\*|__)(.*?)\1)");
        italic_pattern = std::regex(R"((\*|_)(.*?)\1)");
        del_pattern = std::regex(R"((~~)(.*?)\1)");
        hr_pattern = std::regex(R"(^-{3,}$)");
        ul_li_pattern = std::regex(R"(^([\s]*)[-\*\+] +(.*))");
        ol_li_pattern = std::regex(R"(^([\s]*)[0-9]+\.(.*))");
        /**处理超链接的正则表达式，需要考虑到[[...](...)...)的情况**/
        link_pattern = std::regex(R"(\[([^\[]+)\]\(([^\)]+)\))");
        /**处理图片的正则表达式，需要考虑到![[...]]](....))——只要考虑匹配最外的中括号即可**/
        img_pattern = std::regex(R"(!\[(.+)\]\(([^\)]+)\))");
        /**处理代码块的正则表达式**/
        code_pattern = std::regex(R"(```([\s\S]*?)```[\s]?)");
        /**处理内联代码块的正则表达式**/
        inline_code_pattern = std::regex(R"(`{1,2}[^`](.*?)`{1,2})");
        /**处理引用块的正则表达式**/
        //blockquoting_pattern = std::regex(R"(^(&gt;|\>)(.*))");
        blockquoting_pattern = std::regex(R"(^([&gt;\>]+)(.*))");
        /**处理表格的正则表达式**/
        table_pattern = std::regex(R"((\|[^\n]+\|\r?\n)((?:\|:?[-]+:?)+\|)(\n(?:\|[^\n]+\|\r?\n?)*)?)");
        /**初始化handler，针对每一个pattern指定对应的处理函数**/
        /**规定1: [优先级] 先处理图片，再处理链接**/
        /**2. 先处理blockquoting, ul, ol, headline, hr等需要效果作用于一行的md元素，再处理其他不作用于一行的md元素，比如字体等**/
        regex_handler = std::vector<markdown_regex_expression> {
                /**作用于一行的元素，其需要对整整一行进行转换工作，为了不影响正则表达式的匹配（一般都是^开头），需要将他们的优先级放在上层**/
                /**而这五个元素之间的顺序则不必考虑，因为他们之前都是互斥的（^ 开头）**/
                std::make_pair(blockquoting_pattern, [this](auto && PH1, auto && PH2) { return parseBlockquoting(std::forward<decltype(PH1)>(PH1), std::forward<decltype(PH2)>(PH2)); }),
                std::make_pair(ul_li_pattern, [this](auto && PH1, auto && PH2) { return parseBulletList(std::forward<decltype(PH1)>(PH1), std::forward<decltype(PH2)>(PH2)); }),
                std::make_pair(ol_li_pattern, [this](auto && PH1, auto && PH2) { return parseNumberedList(std::forward<decltype(PH1)>(PH1), std::forward<decltype(PH2)>(PH2)); }),

                std::make_pair(headline_pattern, [this](auto && PH1, auto && PH2) { return parseHeadline(std::forward<decltype(PH1)>(PH1), std::forward<decltype(PH2)>(PH2)); }),
                std::make_pair(hr_pattern, [this](auto && PH1, auto && PH2) { return parseHr(std::forward<decltype(PH1)>(PH1), std::forward<decltype(PH2)>(PH2)); }),

                /**不作用于一行的元素，比如加粗、加斜、加删除线、加图片、链接和内联代码，他们能内嵌到一行中的各个位置，所以放在最后解析对正则表达式的匹配不产生影响**/
                std::make_pair(bold_pattern, [this](auto && PH1, auto && PH2) { return parseBold(std::forward<decltype(PH1)>(PH1), std::forward<decltype(PH2)>(PH2)); }),
                std::make_pair(italic_pattern, [this](auto && PH1, auto && PH2) { return parseItalic(std::forward<decltype(PH1)>(PH1), std::forward<decltype(PH2)>(PH2)); }),
                std::make_pair(del_pattern, [this](auto && PH1, auto && PH2) { return parseDel(std::forward<decltype(PH1)>(PH1), std::forward<decltype(PH2)>(PH2)); }),
                std::make_pair(img_pattern, [this](auto && PH1, auto && PH2) { return parseImage(std::forward<decltype(PH1)>(PH1), std::forward<decltype(PH2)>(PH2)); }),
                std::make_pair(link_pattern, [this](auto && PH1, auto && PH2) { return parseLink(std::forward<decltype(PH1)>(PH1), std::forward<decltype(PH2)>(PH2)); }),
                std::make_pair(inline_code_pattern, [this](auto && PH1, auto && PH2) { return parseInlineCode(std::forward<decltype(PH1)>(PH1), std::forward<decltype(PH2)>(PH2)); }),
        };

        /**针对一些效果作用于一块（占用多行）的元素，需要额外划分出来解析，比如表格，代码**/
        /**至于blockquoting, ul和ol，由于每一行的格式都是一样的，就按照行来解析**/
        regex_handler_block = std::vector<markdown_regex_expression> {
                std::make_pair(code_pattern, [this](auto && PH1, auto && PH2) { return parseCode(std::forward<decltype(PH1)>(PH1), std::forward<decltype(PH2)>(PH2)); }),
                std::make_pair(table_pattern, [this](auto && PH1, auto && PH2) { return parseTable(std::forward<decltype(PH1)>(PH1), std::forward<decltype(PH2)>(PH2)); }),
        };

        /**初始化引用块处理层数为0**/
        blockquote_level = 0;

        /**两个列表的初始状态栈全部为-1**/
        ul_level.push(-1);
        ol_level.push(-1);
    }


    std::string MarkdownP::parseLine(std::string line)
    {
        const int UL_POS = 1; //处理ul列表的handler处于regex_handler的位置，下同
        const int OL_POS = 2;
        const int BLOCKQUOTE_POS = 0;

        /**UPDATE——当前行对应的有序列表和无序列表的"深度值"，在后续的正则匹配中所赋值**/
        int handle_ul_level = -1;
        int handle_ol_level = -1;

        /**本次parse过程中是否处理到blockquote，用于引用块处理，和列表状态分开，因为他们是可以同时作用的（引用块内嵌列表）**/
        bool handle_blockquote = false;
        int handle_blockquote_level = 0;
        /**该行是否需要加上标签<p>...</p>，如果该行不处于引用块和列表，且不是分隔符和标题，需加上**/
        bool need_add_label_p = true;

        /**要注意此时的curr已经是旧的状态了**/

        for(int i = 0;i < regex_handler.size();i++)
        {
            auto &re = regex_handler[i];
            if(std::regex_search(line, std::get<0>(re)))
            {
                need_add_label_p = !(i < 5 and i > 0) and need_add_label_p;
                if(i == BLOCKQUOTE_POS)
                {
                    /**如果处理到引用块，需要分析出大于号的数目，以便获知当前行所在第几层的引用块**/
                    std::smatch m;
                    std::regex_match(line, m, regex_handler[BLOCKQUOTE_POS].first);
                    handle_blockquote_level = static_cast<int>(m[1].str().length()); //m[1].str().length() 为>符号的数目，因为第一个分组就是匹配到各个大于号
                }
                /**根据迭代的情况，标记当前处理列表状况，有序列表和无序列表是互斥的**/
                if(i == UL_POS)
                {
                    /**根据匹配结果得到当前行的"深度值"，即空白符的数目，下同**/
                    std::smatch m;
                    std::regex_match(line, m, regex_handler[UL_POS].first);
                    handle_ul_level = static_cast<int>(m[1].str().length());
                } else if(i == OL_POS)
                {
                    std::smatch m;
                    std::regex_match(line, m, regex_handler[OL_POS].first);
                    handle_ol_level = static_cast<int>(m[1].str().length());
                }

                /**FIXED: 最后才将该行的主体信息提取出来**/
                line = std::get<1>(re)(line, std::get<0>(re));
            }
        }

        if(need_add_label_p and line[0] != '<')
        {
            line = "<p>" + line + "</p>";
        }
        if(need_add_label_p and (line.find("</ul>") == 0 or line.find("</ol>") == 0))
        {
            line.insert(5, "\n<p>").append("\n</p>");
        }

        /**********************************************/
        /****************先添加左标签********************/
        /**因为，标签的添加逻辑都是从最左边开始添加，为了避免左标签
        添加到左兄弟的右标签上******************************
        **其次，在内部，先处理<ul>和<ol>标签再添加<blockquote>
        **，因为允许在<blockquote>中添加列表***************/
        /**********************************************/

        /**如果状态栈中的"深度值"小于当前列表项的"深度值"，意味着该行已经进去了更深一层的列表，此时插入一个左标签以开始一个新的嵌套列表，并将当前的
         * "深度值"放进状态栈中**/
        if(handle_ul_level > ul_level.top())
        {
            line.insert(0, "<ul>\n");
            ul_level.push(handle_ul_level);
        }

        if(handle_ol_level > ol_level.top())
        {
            line.insert(0, "<ol>\n");
            ol_level.push(handle_ol_level);
        }

        /**UPDATE 20190517---支持嵌套引用块**/
        /**如果blockquote_level（上行引用块处理层数）小于本行处理的层数，意味着进入了更深的层次，需要加上标签<blockquote>**/
        /**要注意可能不止进入深一层，也有可能深几层，所以要通过循环加入多个标签**/
        if(handle_blockquote_level > blockquote_level)
        {
            std::string tmp;
            for(int i = handle_blockquote_level;i > blockquote_level;i--)
            {
                tmp += "<blockquote>\n";
            }
            line.insert(0, tmp);
        }

        /**********************************************/
        /****************再添加右标签********************/
        /**请注意，右标签是添加在原文档中下一行的头部并加上\n**/
        /**而不是在最后一个元素加上右标签*******************/
        /**因为，标签的添加逻辑都是从最左边开始添加，为了避免左标签
        添加到左兄弟的右标签上******************************
        **其次，在内部，标签的处理顺序要反过来了**************/
        /**********************************************/

        /**FIXED: 结束状态要统一处理，全部最后时刻放在一行数据中的最前面**/

        /**UPDATE 20190517---支持嵌套引用块**/
        /**如果blockquote_level（上行引用块处理层数）大于本行处理的层数，意味着从深的层次跳出来了，需要加上标签</blockquote>闭合更深一层的标签**/
        if(handle_blockquote_level < blockquote_level)
        {
            std::string tmp;
            for(int i = handle_blockquote_level;i < blockquote_level;i++)
            {
                tmp += "</blockquote>\n";
            }
            line.insert(0, tmp);
        }

        /**UPDATE 20190518---支持有序列表和无序列表的嵌套**/
        /**如果状态栈中的"深度值"大于当前列表项的"深度值"，意味着该行已经跳出了一个或者多个列表的嵌套，此时弹出栈，每弹出一个元素插入一个右标签以闭合一层嵌套，
         * 直到栈顶元素小于等于当前状态值即可，在这里，进去只能进去深一层，但可以出去多层**/
        if(handle_ul_level < ul_level.top())
        {
            while(ul_level.top() > handle_ul_level)
            {
                line.insert(0, "</ul>\n");
                ul_level.pop();
            }
        }
        if(handle_ol_level < ol_level.top())
        {
            while(ol_level.top() > handle_ol_level)
            {
                line.insert(0, "</ol>\n");
                ol_level.pop();
            }
        }

        /**FIXED: 迟更新，直到所有工作处理完之后才更新curr为handle_state，避免标签插入异常**/
        blockquote_level = handle_blockquote_level;  // 更新处理的引用块层数

        return line + "\n";
    }

    std::string MarkdownP::parseBlock(std::string text)
    {
        for(auto &re : regex_handler_block)
        {
            if(std::regex_search(text, std::get<0>(re)))
            {
                text = std::get<1>(re)(text, std::get<0>(re));
            }
        }
        return text;
    }


    std::string MarkdownP::parse(std::string text)
    {
        /**解析函数的外部接口**/
        /**该类的处理方法: 将md元素分为两类，一类是以块为域的md元素；另一类是以行为域的md元素**/
        /**其中，以块为域的元素，比如表格、代码，其解析范围需要扩展到多行来看待，不能孤立地看做一行来解析**/
        /**而以行为域的元素则可以孤立成一行来看待，而列表、引用块由于每一行的格式差不多，所以也可以分成一行来处理，附以一些状态判帮助外标签的插入即可，所以不必要当做块来对待**/
        /**处理顺序为：先处理块元素，再处理行元素，最后处理行内元素（第二第三放在一起进行，调整优先级即可）**/


        /**在原文尾部加上\n,为了闭合列表的标签**/
        text += "\n ";
        /**先处理块作用的md元素**/
        text = parseBlock(text);
        /**随后按行切割**/
        auto tmp = splitStr(text, "\n");
        text.clear();
        /**一行行地解析**/
        for(auto &line : tmp)
        {
            text += parseLine(line);
        }
        return text;
    }
}