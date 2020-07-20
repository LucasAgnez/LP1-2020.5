#include "Employee.h"

#include <string>

Employee::Employee() : name(""), salary(0), cpf(""), admission_date("")
{
}

Employee::Employee(std::string name) : name(name), salary(0), cpf(""), admission_date("")
{
}
