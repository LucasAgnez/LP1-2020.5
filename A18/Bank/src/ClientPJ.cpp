#include "ClientPJ.h"


int ClientPJ::total_clientsPJ;

ClientPJ::ClientPJ() : company_name(""), cnpj("")
{
  this->total_clientsPJ += 1;
}

ClientPJ::ClientPJ(std::string company_name, std::string cnpj) : company_name(company_name), cnpj(cnpj)
{
  this->total_clientsPJ += 1;
}

std::string ClientPJ::get_company_name() {
  return this->company_name;
}
void ClientPJ::set_company_name(std::string rs) {
  this->company_name = rs;
}
std::string ClientPJ::get_cnpj() {
  return this->cnpj;
}
void ClientPJ::set_cnpj(std::string c) {
  this->cnpj = c;
}

