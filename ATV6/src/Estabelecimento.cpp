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

void Estabelecimento::venda(Produto& produto){}

void Estabelecimento::caixa(std::string tipo){
  Produto item;
  std::string arquivo_caixa = tipo + "_caixa.csv";
  std::ofstream caixa(arquivo_caixa);
  caixa << "COD,PRODUTO,UNIDADE DE MEDIDA,PREÇO,QUANTIDADE" << std::endl;
  for(size_t i = 0; i < vendas.size(); i++){
    item = vendas[i];
    caixa << produtos.at(i).codigo << ",";
    caixa << produtos.at(i).nome << ",";
    caixa << produtos.at(i).unidade << ",";
    caixa << "R$ " << produtos.at(i).preco << ",";
    caixa << produtos.at(i).quantidade;
    caixa << std::endl;
  }
  caixa << "Lucro total: " << lucro << std::endl;
  caixa.close();
}
