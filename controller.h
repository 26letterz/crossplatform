#pragma once
#include "feedback.h"
#include <string>

Feedback controller_write(std::string index, std::string value);
Feedback controller_read(std::string record);
Feedback controller_delete(std::string record);
Feedback controller_update(std::string record, std::string new_value);