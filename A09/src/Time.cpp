#include "Time.h"

Time::Time() : hour{0}, minute{0}, second{0} 
{
}

void Time::set_from_string(const std::string& time)
{
    std::stringstream stream(time);
    char discard;
    if(time.at(0) == '-'){ 
      stream >> discard;
       
    }
    Time::set_from_string(stream);
}

void Time::set_from_string(std::stringstream& stream)
{
    char discard;
    stream >> hour;
    stream >> discard;
    stream >> minute;
    stream >> discard;
    stream >> second;
}

std::string Time::to_string()
{
    std::stringstream stream;

    if (hour < 10) {
        stream << '0';
    }
    stream << hour;
    stream << ':';

    if (minute < 10) {
        stream << '0';
    }
    stream << minute << ':';
    
    if (second < 10) {
        stream << '0';
    }
    stream << second;

    return stream.str();
}
