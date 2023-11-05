//
// Created by Nanomoa on 23-11-3.
//

#include <iostream>
#include <sstream>
#include "ConfiguredDecorator.h"


namespace Markdown
{
    std::string ConfiguredDecorator::decorate()
    {
        std::stringstream ss;
        for(auto &item : _settings)
        {
            ss << "." << item.first << "{ " << item.second << " }\n";
        }
        return ss.str();
    }
}