#pragma once
#include <string>
#include "feedback.h"

Feedback model_write(std::string record);
Feedback model_read(std::string record);
Feedback model_delete(std::string record);
Feedback model_update(std::string record, std::string new_value);