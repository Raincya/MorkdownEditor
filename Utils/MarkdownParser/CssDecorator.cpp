//
// Created by Nanomoa on 23-11-3.
//

#include <iostream>
#include <sstream>
#include "CssDecorator.h"
#include "../StringUtil/StringUtil.h"


namespace Markdown
{
    std::string CssDecorator::decorate()
    {
        return readFileAll(_css_filename);
    }
}