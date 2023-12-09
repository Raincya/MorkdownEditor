#include <string>

struct ServerConfig
{
    const std::string url = "http://127.0.0.1:4561/";
    std::string login()
    {
        return url + "user/login";
    }
    std::string reg()
    {
        return url + "user/reg";
    }
};