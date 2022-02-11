#include "controller.h"
#include "model.h"

Feedback controller_write(std::string index, std::string value) {
    std::string record = index + " " + value;
    return model_write(record);
}

Feedback controller_read(std::string record) {
    return model_read(record);
}

Feedback controller_delete(std::string record) {
    return model_delete(record);
}

Feedback controller_update(std::string record, std::string new_value) {
    return model_update(record, new_value);
}