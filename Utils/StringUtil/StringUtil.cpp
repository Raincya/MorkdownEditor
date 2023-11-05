//
// Created by Nanomoa on 23-11-3.
//

#include <algorithm>
#include <fstream>
#include <cstdlib>
#include <iostream>
#include <sstream>
#include "StringUtil.h"

std::vector<std::string> splitStr(const std::string &str, const std::string &delim)
{
    std::vector<std::string> tokens;
    size_t prev = 0, pos = 0;
    do {
        pos = str.find(delim, prev);
        if(pos == std::string::npos)
        {
            pos = str.length();
        }
        std::string token = str.substr(prev, pos - prev);
        if(!token.empty())
        {
            tokens.push_back(token);
        }
        prev = pos + delim.length();
    } while(pos < str.length() and prev < str.length());
    return tokens;
}

void ltrim(std::string &s)
{
    s.erase(s.begin(), std::find_if(s.begin(), s.end(), [](int ch) -> bool
    {
        return !std::isspace(ch);
    }));
}

void rtrim(std::string &s)
{
    s.erase(std::find_if(s.rbegin(), s.rend(), [](int ch) -> bool
    {
        return !std::isspace(ch);
    }).base(), s.end());
}

void trim(std::string &s)
{
    ltrim(s);
    rtrim(s);
}

std::string ltrimCopy(std::string s)
{
    ltrim(s);
    return s;
}

std::string rtrimCopy(std::string s)
{
    rtrim(s);
    return s;
}

std::string trimCopy(std::string s)
{
    trim(s);
    return s;
}

std::string readFileAll(const std::string &filename)
{
    std::ifstream file(filename);
    if(!file)
    {
        std::cerr << "Cannot open input file \"" << filename << "\"" << std::endl;
        exit(EXIT_FAILURE);
    }
    std::stringstream ret;
    ret << file.rdbuf();  // 输出全部内容
    file.close();
    return ret.str();
}

void writeToFile(const std::string &filename, const std::string &content)
{
    std::ofstream file(filename);
    if(!file)
    {
        std::cerr << "Cannot open output file \"" << filename << "\"" << std::endl;
        exit(EXIT_FAILURE);
    }
    file << content;
    file.close();
}