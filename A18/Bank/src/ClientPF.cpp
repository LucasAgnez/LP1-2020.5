#include "ClientPF.h"

#include <string>

int ClientPF::total_clientsPF;

ClientPF::ClientPF() : cpf("")
{
  this->total_clientsPF += 1;
}

ClientPF::ClientPF(std::string name, std::string cpf) : Client(name), cpf(cpf)
{
  this->total_clientsPF += 1;
}
