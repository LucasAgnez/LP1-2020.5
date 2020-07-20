#include "Menager.h"

#include <string>

Menager::Menager() : sector("")
{
}

Menager::Menager(std::string name, std::string setSector) : Employee(name), sector(sector)
{
}
