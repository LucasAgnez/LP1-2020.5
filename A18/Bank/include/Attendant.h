#if !defined(ATTENDANT)
#define ATTENDANT

#include "Employee.h"

class Attendant : public Employee
{
private:
  bool preferencial;
public:
  Attendant();
  Attendant(std::string name, bool preferencial);

  bool isPreferencial() {
    return this->preferencial;
  }
  void setPreferencial(bool p) {
    this->preferencial = p;
  }
};

#endif
