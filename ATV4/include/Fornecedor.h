#ifndef FORNECEDOR_H
#define FORNECEDOR_H

#include "VectorSupermercado.h"
#include "Produto.h"

class Fornecedor
{
private:
  VectorSupermercado<Produto> produtos;
public:
  Fornecedor(/* args */);
  ~Fornecedor();

  void load();
  void update();

  VectorSupermercado<Produto> getProdutos() {
    return this->produtos;
  }
  void setProdutos(VectorSupermercado<Produto> p) {
    this->produtos = p;
  }
};

#endif // FORNECEDOR_H
