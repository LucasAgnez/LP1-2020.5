#include "Estabelecimento.h"
#include "Fornecedor.h"


Estabelecimento::Estabelecimento() :
  lucro(0), numero_clientes(0), filename("")
{
}

Estabelecimento::Estabelecimento(std::string filename) :
  lucro(0), numero_clientes(0), filename(filename)
{
}

Estabelecimento::~Estabelecimento()
{
}

void Estabelecimento::registrar_venda(Produto item) {
  for(size_t i = 0; i < vendas.size(); i++){
    if(item.nome == vendas[i].nome){
      vendas[i].quantidade += item.quantidade;
      return;
    }
  }
  vendas.push_back(item);
}




