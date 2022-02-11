#pragma once
#include <string>

struct Feedback {
    bool success;
    bool return_value;
    std::string content;

    Feedback():
        success(0),return_value(0) {}

    Feedback(bool _success, bool _return_value, std::string _content): 
        success(_success), return_value(_return_value), content(_content) {}
};