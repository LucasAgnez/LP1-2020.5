#if !defined(FORNECEDOR_H)
#define FORNECEDOR_H

#include "VectorSupermercado.h"
#include "Produtos.h"

class Fornecedor
{
private:
  VectorSupermercado<Produto> produtos;
  int quantidade_produtos;

public:
  Fornecedor();
  ~Fornecedor();

  void load();
  void update();
  void listar();

};

#endif // FORNECEDOR_H
