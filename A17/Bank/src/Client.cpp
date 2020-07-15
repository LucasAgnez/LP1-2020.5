#include "Client.h"

int Client::clients_number;

Client::Client() : name(""), cpf("")
{
  this->clients_number += 1;
}

Client::Client(std::string name, std::string cpf) : name(name), cpf(cpf)
{
  this->clients_number += 1;
}
