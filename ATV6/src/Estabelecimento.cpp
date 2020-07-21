#include "Estabelecimento.h"
#include "Fornecedor.h"


Estabelecimento::Estabelecimento() :
  lucro(0), numero_vendas(0), numero_clientes(0), filename("")
{
}

Estabelecimento::Estabelecimento(std::string filename) :
  lucro(0), numero_vendas(0), numero_clientes(0), filename(filename)
{
}

Estabelecimento::~Estabelecimento()
{
}

void Estabelecimento::registrar_venda(Produto item) {
  for(int i = 0; i < numero_vendas; i++){
    if(item.codigo == vendas[i].codigo){
      vendas[i].quantidade++;
      return;
    }
  }
  item.quantidade = 1;
  vendas.push_back(item);
  numero_vendas++;
}

int Estabelecimento::venda(int codigo){}

void Estabelecimento::caixa(std::string tipo){
  Produto item;
  std::string arquivo_caixa = tipo + "_caixa.csv";
  std::ofstream caixa(arquivo_caixa);
  caixa << "COD,PRODUTO,UNIDADE DE MEDIDA,PREÇO,QUANTIDADE" << std::endl;
  for(int i = 0; i < numero_vendas; i++){
    item = vendas[i];
    caixa << produtos.at(i).codigo << ",";
    caixa << produtos.at(i).nome << ",";
    caixa << produtos.at(i).unidade << ",";
    caixa << "\"R$ " << produtos.at(i).preco << "\",";
    caixa << produtos.at(i).quantidade;
    caixa << std::endl;
  }
  caixa << "Lucro total: " << lucro << std::endl;
  caixa.close();
}
