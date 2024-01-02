#include <string>

struct ServerConfig
{
    const std::string url = "http://127.0.0.1:4561/";

    static std::string login()
    {
        return "/user/login";
    }

    static std::string reg()
    {
        return "/user/reg";
    }
};