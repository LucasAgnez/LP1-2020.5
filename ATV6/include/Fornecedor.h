#ifndef W5_FORNECEDOR_H
#define W5_FORNECEDOR_H

#include "VectorSupermercado.h"
#include "Produto.h"

class Fornecedor
{
private:
  VectorSupermercado<Produto> produtos;
  void load();
  void update();

public:
  Fornecedor();
  ~Fornecedor();
  
  void listar();
  bool repassaProdutos(std::string produto, int quantidade);
};

#endif // W5_FORNECEDOR_H
