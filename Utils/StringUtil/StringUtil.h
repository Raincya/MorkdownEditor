//
// Created by Nanomoa on 23-11-3.
//

#ifndef MARKDOWNEDITOR_STRINGUTIL_H
#define MARKDOWNEDITOR_STRINGUTIL_H

#include <string>
#include <vector>

/**
 * @name splitStr
 * @brief 按delim切割字符串
 * @param str 要切割的字符串
 * @param delim 分隔符
 * @return std::vector<std::string> 切割后的子字符串集合
 * **/
std::vector<std::string> splitStr(const std::string &str, const std::string &delim);

/**
 * @name ltrim
 * @brief 修剪字符串s左侧的空白字符
 * @param s 要修剪的字符串
 * @return void 就地修剪
 * **/
void ltrim(std::string &s);

/**
 * @name rtrim
 * @brief 修剪字符串s右侧的空白字符
 * @param s 要修剪的字符串
 * @return void 就地修剪
 * **/
void rtrim(std::string &s);

/**
 * @name rtrim
 * @brief 修剪字符串s两侧的空白字符
 * @param s 要修剪的字符串
 * @return void 就地修剪
 * **/
void trim(std::string &s);

/**
 * @name ltrimCopy
 * @brief 修剪字符串s左侧的空白字符
 * @param s 要修剪的字符串
 * @return string 修剪后的字符串
 * **/
std::string ltrimCopy(std::string s);

/**
 * @name ltrimCopy
 * @brief 修剪字符串s右侧的空白字符
 * @param s 要修剪的字符串
 * @return string 修剪后的字符串
 * **/
std::string rtrimCopy(std::string s);

/**
 * @name ltrimCopy
 * @brief 修剪字符串s两侧的空白字符
 * @param s 要修剪的字符串
 * @return string 修剪后的字符串
 * **/
std::string trimCopy(std::string s);

std::string readFileAll(const std::string &filename);

void writeToFile(const std::string &filename, const std::string &content);

#endif //MARKDOWNEDITOR_STRINGUTIL_H
