#if !defined(SECURITY_H)
#define SECURITY_H

#include "Employee.h"

class Security : public Employee
{
private:
  bool shift;

public:
  Security();
  Security(std::string name, bool shift);

  bool is_in_shift() {
    return this->shift;
  }
  void set_shift(bool p) {
    this->shift = p;
  }
};

#endif
