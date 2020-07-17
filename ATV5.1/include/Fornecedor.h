#ifndef FORNECEDOR_H
#define FORNECEDOR_H

#include "VectorSupermercado.h"
#include "Produto.h"

class Fornecedor
{
private:
  VectorSupermercado<Produto> produtos;
  int quantidade_produtos;
  void load();
  void update();

public:
  Fornecedor();
  ~Fornecedor();
  
  void listar();
  bool repassaProdutos(std::string produto, int quantidade);
};

#endif // FORNECEDOR_H
