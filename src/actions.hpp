#pragma once

#include <string>

namespace actions {
    
    void calculator();

    void exitApp();

    void getAction(std::string* data, const std::string& message);
}