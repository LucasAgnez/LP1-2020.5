#include "Attendant.h"

#include <string>

Attendant::Attendant() : preferencial(false)
{
}

Attendant::Attendant(std::string name, bool preferencial) : Employee(name), preferencial(preferencial)
{
}
