#ifndef W5N_TIME_H
#define W5N_TIME_H

#include <string>
#include <sstream>
#include "DateTime.h"

struct Time
{
    Time();
    unsigned hour;
    unsigned minute;
    unsigned second;

    void set_from_string(const std::string& time);
    void set_from_string(std::stringstream& time);
    std::string to_string();
};
#endif
