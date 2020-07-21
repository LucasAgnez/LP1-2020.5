#ifndef W5_PRODUTOS_H
#define W5_PRODUTOS_H

#include "Produto.h"
#include <string>

struct Produto{
  int codigo;
  std::string nome;
  std::string unidade;
  double preco;
  int quantidade;
};

#endif
