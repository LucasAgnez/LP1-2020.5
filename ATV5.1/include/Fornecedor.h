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

  VectorSupermercado<Produto> getProdutos() {
    return this->produtos;
  }
  void setProdutos(VectorSupermercado<Produto> p) {
    this->produtos = p;
  }
};

#endif // FORNECEDOR_H
