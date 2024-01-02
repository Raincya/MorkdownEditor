cmake_minimum_required(VERSION 3.26)
project(MarkdownEditor)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt6 COMPONENTS
        Core
        Gui
        Widgets
        Network
        Quick
        WebEngineQuick
        REQUIRED)

add_executable(MarkdownEditor main.cpp
        Utils/HttpClient/HttpClient.h
        Utils/MarkdownParser/AbsractParser.h
        Utils/MarkdownParser/AbstractDecorator.h
        Utils/MarkdownParser/AbstractMarkdown.cpp
        Utils/MarkdownParser/Configurable.cpp
        Utils/MarkdownParser/ConfiguredDecorator.cpp
        Utils/MarkdownParser/CssDecorator.cpp
        Utils/MarkdownParser/Markdown.cpp
        Utils/MarkdownParser/Parser.cpp
        Utils/StringUtil/StringUtil.cpp
        Utils/StringUtil/StringUtil.h
        Utils/Json/configor.hpp
        Utils/Json/configor_conversion.hpp
        Utils/Json/configor_declare.hpp
        Utils/Json/configor_encoding.hpp
        Utils/Json/configor_exception.hpp
        Utils/Json/configor_iterator.hpp
        Utils/Json/configor_parser.hpp
        Utils/Json/configor_serializer.hpp
        Utils/Json/configor_stream.hpp
        Utils/Json/configor_token.hpp
        Utils/Json/configor_value.hpp
        Utils/Json/configor_wrapper.hpp
        Utils/Json/json.hpp
        Config/ServerConfig.h
        Pages/LoginAndRegister/LoginAndRegController.h
        Pages/LoginAndRegister/LoginAndRegModel.h
        Utils/Timer/Timer.cpp
        Utils/Timer/Timer.h
        Pages/Main/MainModel.h
        Pages/Main/MainController.h
)

target_link_libraries(MarkdownEditor
        Qt6::Core
        Qt6::Gui
        Qt6::Widgets
        Qt6::Network
        Qt6::Quick
        Qt6::WebEngineQuick
)
