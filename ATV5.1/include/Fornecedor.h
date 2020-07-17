#if !defined(FORNECEDOR_H)
#define FORNECEDOR_H

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

  bool repassaProdutos(std::string produto, int quantidade);

  VectorSupermercado<Produto> getProdutos() {
    return this->produtos;
  }
  void setProdutos(VectorSupermercado<Produto> p) {
    this->produtos = p;
  }
};

#endif // FORNECEDOR_H
