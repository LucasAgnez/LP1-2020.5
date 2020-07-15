#ifndef W5_AGENCY_H
#define W5_AGENCY_H

#include <iostream>
#include <string>

class Agency{
  public:
  Agency();
  Agency(std::string number, std::string name);

  std::string number;
  std::string name;
};

#endif
