#if !defined(CLIENTPF_H)
#define CLIENTPF_H

#include "Client.h"

#include <string>

class ClientPF : public Client
{
public:
  ClientPF();
  ClientPF(std::string name, std::string cpf);

  std::string cpf;
  static int total_clientsPF;

  std::string getCpf() {
    return this->cpf;
  }
  void setCpf(std::string c) {
    this->cpf = c;
  }
};

#endif
