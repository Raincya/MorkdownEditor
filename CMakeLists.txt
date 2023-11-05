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
        REQUIRED)

add_executable(MarkdownEditor main.cpp
        Utils/HttpClient/HttpClient.cpp
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
        Pages/LoginAndRegister/Model.cpp
        Pages/LoginAndRegister/Controller.cpp
)

target_link_libraries(MarkdownEditor
        Qt6::Core
        Qt6::Gui
        Qt6::Widgets
        Qt6::Network
        Qt6::Quick
)
