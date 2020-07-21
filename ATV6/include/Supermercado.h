#ifndef W5_SUPERMERCADO_H
#define W5_SUPERMERCADO_H

#include "Estabelecimento.h"
#include "Fornecedor.h"

class Supermercado : public Estabelecimento
{
private:
  Fornecedor fornecedor;
public:
  Supermercado();
  Supermercado(std::string estoqueFilename);
  ~Supermercado();

  // Carregar o arquivo estoque.csv
  void load();
  void listar();
  int venda(int codigo);

  void reabastecerEstoque();
  void atualizarEstoque();
};

#endif // W5_SUPERMERCADO_H
