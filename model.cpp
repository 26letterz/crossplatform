#include <iostream>
#include <fstream>
#include "model.h"

Feedback model_write(std::string record)
{

    std::fstream db;
    Feedback result;
    db.open("db.txt", std::ios::out | std::ios::app);

    if (!db)
    {
        goto end;
    }
    db << record << "\n";
    db.close();
    result.success = 1;
    result.return_value = 1;

end:
    return result;
}

Feedback model_read(std::string record) // if success == 0 then some db error; if success == 1 and return value == 0 then not found
{
    std::fstream db;
    Feedback result;
    std::string line, index;
    db.open("db.txt", std::ios::in);

    if (!db)
    {
        goto end;
    }

    while (std::getline(db, line))
    {
        size_t space_pos = line.find(" ");
        if (space_pos != std::string::npos)
        {
            index = line.substr(0, space_pos);
            if (index == record)
            {
                result.return_value = 1;
                result.content = line.substr(space_pos + 1);
                break;
            }
        }
    }
    result.success = 1;

end:
    return result;
}

Feedback model_delete(std::string record)
{
    std::fstream db;
    Feedback result;
    db.open("db.txt", std::ios::in);
    std::string line, index, replacement;

    if (!db)
    {
        goto end;
    }

    while (std::getline(db, line))
    {
        size_t space_pos = line.find(" ");
        if (space_pos != std::string::npos)
        {
            index = line.substr(0, space_pos);
            if (index != record)
            {
                replacement += line + "\n";
            }
            else
            {
                result.return_value = 1;
            }
        }
    }
    db.close();

    db.open("db.txt", std::ios::out);
    if (!db)
    {
        goto end;
    }

    db << replacement;
    db.close();
    result.success = 1;

end:
    return result;
}

Feedback model_update(std::string record, std::string new_value)
{
    std::fstream db;
    Feedback result;
    db.open("db.txt", std::ios::in);
    std::string line, index, replacement;

    if (!db)
    {
        goto end;
    }

    while (std::getline(db, line))
    {
        size_t space_pos = line.find(" ");
        if (space_pos != std::string::npos)
        {
            index = line.substr(0, space_pos);
            if (index == record)
            {
                replacement += index + " " + new_value + "\n";
                result.return_value = 1;
            }
            else
            {
                replacement += line + "\n";
            }
        }
    }
    db.close();

    db.open("db.txt", std::ios::out);
    if (!db)
    {
        goto end;
    }

    db << replacement;
    db.close();
    result.success = 1;

end:
    return result;
}