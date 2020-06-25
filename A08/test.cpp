#include "Date.h"
#include "Diary.h"

#include <iostream>
#include <sstream>
#include <string>

int main(int argc, char* argv[])
{
    std::stringstream stream(get_current_date);
  char discard;

  stream >> day;
  stream >> discard;
  stream >> month;
  stream >> discard;
  stream >> year;

    std::cout << day << std::endl;
    std::cout << month << std::endl;
    std::cout << year << std::endl;

    return 0;
}
