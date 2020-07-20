#if !defined(EMPLOYEE_H)
#define EMPLOYEE_H

#include <string>

class Employee
{
protected:
  std::string name;
  double salary;
  std::string cpf;
  std::string admission_date;

public:
  Employee();
  Employee(std::string name);

  std::string getName() {
    return this->name;
  }
  void setName(std::string n) {
    this->name = n;
  }
  double getSalario() {
    return this->salary;
  }
  void setSalary(double s) {
    this->salary = s;
  }
  std::string getCpf() {
    return this->cpf;
  }
  void setCpf(std::string c) {
    this->cpf = c;
  }
  std::string getAdmission_date() {
    return this->admission_date;
  }
  void setAdmission_date(std::string da) {
    this->admission_date = da;
  }
};

#endif
