#include <iostream>
#include "feedback.h"
#include "controller.h"

void process_response(const Feedback &response, std::string mode)
{
    if (response.success == 0)
    {
        std::cout << "Error!\n";
    }
    else
    {
        std::cout << "Action completed!\n";
        if ((response.return_value == 1) && (mode == "read"))
        {
            std::cout << "Reply: " << response.content << "\n";
        }
        else if (response.return_value == 1)
        {
            std::cout << "Success!\n";
        }
        else if (response.return_value == 0)
        {
            std::cout << "Entry not found\n";
        }
    }
}

int main(int argc, char *argv[])
{
    if (argc < 3)
    {
        std::cout << "Too few arguments!\n";
    }
    else if (argc == 3)
    {
        if (std::string(argv[1]) == "read")
        {
            process_response(controller_read(std::string(argv[2])), "read");
        }
        else if (std::string(argv[1]) == "delete")
        {
            process_response(controller_delete(std::string(argv[2])), "delete");
        }
        else
        {
            std::cout << "No such command\n";
        }
    }

    else if (argc == 4)
    {
        if (std::string(argv[1]) == "update")
        {
            process_response(controller_update(std::string(argv[2]), std::string(argv[3])), "update");
        }
        else if (std::string(argv[1]) == "write")
        {
            process_response(controller_write(std::string(argv[2]), std::string(argv[3])), "write");
        }
        else
        {
            std::cout << "No such command\n";
        }
    }
    else
    {
        std::cout << "Too many arguments\n";
    }

    return 0;
}