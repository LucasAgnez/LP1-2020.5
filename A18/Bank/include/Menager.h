#if !defined(MENAGER_H)
#define MENAGER_H

#include "Employee.h"

class Menager : public Employee
{
private:
  std::string sector;
public:
  Menager();
  Menager(std::string name, std::string sector);

  std::string getSector() {
    return this->sector;
  }
  void setSector(std::string s) {
    this->sector = s;
  }

};

#endif
