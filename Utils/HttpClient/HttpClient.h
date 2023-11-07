//
// Created by Nanomoa on 23-11-3.
//

#ifndef MARKDOWNEDITOR_HTTPCLIENT_H
#define MARKDOWNEDITOR_HTTPCLIENT_H

#include <functional>
#include <QMap>
#include <QVariant>
#include <QStringList>
#include <QtNetwork/QNetworkReply>
#include <QtNetwork/QNetworkRequest>
#include <QtNetwork/QNetworkAccessManager>

class HttpClientPrivate;

class HttpClient {
public:
    explicit HttpClient(const QString &url);
    ~HttpClient();
    void stop2();

    /**
    * @brief 每创建一个 QNetworkAccessManager 对象都会创建一个线程，当频繁的访问网络时，为了节省线程资源，
    *     可以传入 QNetworkAccessManager 给多个请求共享 (它不会被 HttpClient 删除，用户需要自己手动删除)。
    *     如果没有使用 manager() 传入一个 QNetworkAccessManager，则 HttpClient 会自动的创建一个，并且在网络访问完成后自动删除它。
    *
    * @param  manager 执行 HTTP 请求的 QNetworkAccessManager 对象
    * @return 返回 HttpClient 的引用，可以用于链式调用
    */
    HttpClient& manager(QNetworkAccessManager *manager);

    /**
    * @brief  参数 debug 为 true 则使用 debug 模式，请求执行时输出请求的 URL 和参数等
    *
    * @param  debug 是否启用调试模式
    * @return 返回 HttpClient 的引用，可以用于链式调用
    */
    HttpClient& debug(bool debug);

    /**
    * @brief 添加一个请求的参数，可以多次调用添加多个参数
    *
    * @param name  参数的名字
    * @param value 参数的值
    * @return 返回 HttpClient 的引用，可以用于链式调用
    */
    HttpClient& param(const QString &name, const QVariant &value);

    /**
    * @brief 添加多个请求的参数
    *
    * @param ps QMap 类型的参数，key 为参数名，value 为参数值
    *           可以使用 {{"name", 1}, {"box", 2}} 的方式创建 QMap 对象
    * @return 返回 HttpClient 的引用，可以用于链式调用
    */
    HttpClient& params(const QMap<QString, QVariant> &ps);

    /**
    * @brief 添加请求的参数 (请求体)，使用 Json 格式，例如 "{\"name\": \"Alice\"}"
    *
    * @param json 请求体 (request body) 为 Json 格式的参数字符串
    * @return 返回 HttpClient 的引用，可以用于链式调用
    */
    HttpClient& json(const QString &json);

    /**
    * @brief 添加请求头
    *
    * @param name  请求头的名字
    * @param value 请求头的值
    * @return 返回 HttpClient 的引用，可以用于链式调用
    */
    HttpClient& header(const QString &name, const QString &value);

    /**
    * @brief 添加多个请求头
    *
    * @param nameValues 请求头的名字和值对
    *                   可以使用 {{"name", 1}, {"box", 2}} 的方式创建 QMap 对象
    * @return 返回 HttpClient 的引用，可以用于链式调用
    */
    HttpClient& headers(const QMap<QString, QString>& nameValues);

    /**
    * @brief 注册请求成功的回调函数
    *
    * @param successHandler 成功的回调函数，参数为响应的字符串
    * @return 返回 HttpClient 的引用，可以用于链式调用
    */
    HttpClient& success(std::function<void(const QString &)> successHandler);

    /**
    * @brief 注册请求失败的回调函数
    *
    * @param failHandler 失败的回调函数，参数为失败原因和 HTTP 状态码
    * @return 返回 HttpClient 的引用，可以用于链式调用
    */
    HttpClient& fail(std::function<void(const QString &, int)> failHandler);

    /**
    * @brief 注册请求结束的回调函数，不管成功还是失败请求结束后都会执行
    *
    * @param completeHandler 完成的回调函数，无参数
    * @return 返回 HttpClient 的引用，可以用于链式调用
    */
    HttpClient& complete(std::function<void()> completeHandler);

    /**
    * @brief 设置请求响应的字符集，默认使用 UTF-8
    *
    * @param cs 字符集
    * @return 返回 HttpClient 的引用，可以用于链式调用
    */
    HttpClient& charset(const QString &cs);

    /**
    * @brief 执行 GET 请求
    */
    void get();

    /**
    * @brief 执行 POST 请求
    */
    void post();

    /**
    * @brief 执行 PUT 请求
    */
    void put();

    /**
    * @brief 执行 DELETE 请求，由于 delete 是 C++ 的运算符，所以用同义词 remove
    *        注意: Qt 提供的 DELETE 请求是不支持传递参数的，
    *        请参考 QNetworkAccessManager::deleteResource(const QNetworkRequest &request)
    */
    void remove();

    /**
    * @brief 使用 GET 进行下载，下载的文件保存到 savePath
    *
    * @param savePath 下载的文件保存路径
    */
    void download(const QString &savePath);

    /**
    * @brief 上传单个文件
    *        使用 POST 上传，服务器端获取文件的参数名为 file
    *
    * @param path 要上传的文件的路径
    */
    void upload(const QString &path);

    /**
    * @brief 上传文件，文件的内容已经读取到 data 中
    *        使用 POST 上传，服务器端获取文件的参数名为 file
    *
    * @param path 要上传的文件的路径
    */
    void upload(const QByteArray &data);

    /**
    * @brief 上传多个文件
    *        使用 POST 上传，服务器端获取文件的参数名为 files
    *
    * @param paths 要上传的文件的路径
    */
    void upload(const QStringList &paths);

private:
    HttpClientPrivate *d;
};

#endif //MARKDOWNEDITOR_HTTPCLIENT_H
