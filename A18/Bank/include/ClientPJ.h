#ifndef W5_CLIENTPJ_H
#define W5_CLIENTPJ_H

#include "Client.h"

#include <string>

class ClientPJ : public Client
{
public:
  ClientPJ();
  ClientPJ(std::string company_name, std::string cnpj);

  std::string company_name;
  std::string cnpj;
  static int total_clientsPJ;

  std::string get_company_name();
  void set_company_name(std::string rs);
  std::string get_cnpj();
  void set_cnpj(std::string c);
};

#endif
