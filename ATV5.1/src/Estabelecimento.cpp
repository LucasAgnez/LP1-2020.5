#include "Estabelecimento.h"
#include "Fornecedor.h"


Estabelecimento::Estabelecimento() :
  estoque(200), quantidade_produtos(0), produtos(nullptr), lucro(0), numero_vendas(0), numero_clientes(0)
{
  std::string linha;
  std::ifstream arquivo("estoque.csv");
  produtos = new Produto[estoque];
  while(!arquivo.eof()){
    if(quantidade_produtos >= estoque){
      aumentar_estoque();
      continue;
    }
    getline(arquivo, linha);
    if (linha.size() == 0) {
      continue;
    }
    if(linha.at(0) == 'C'){
      continue;
    }
    else {
      std::size_t found = linha.find(",");
        produtos[quantidade_produtos].codigo = set_int2(linha.substr(0,found));
        linha.erase(0, found + 1);

      found = linha.find(",");
        produtos[quantidade_produtos].nome = linha.substr(0,found);
        linha.erase(0, found+1);

      found = linha.find(",");
        produtos[quantidade_produtos].unidade = linha.substr(0,found);
        linha.erase(0, found+1);

      found = linha.find(",");
        produtos[quantidade_produtos].preco = set_double(linha.substr(0,found));
        linha.erase(0, found+1);

      found = linha.find(",");
        produtos[quantidade_produtos].quantidade = set_int(linha);
    }
    quantidade_produtos++;
  }
}

Estabelecimento::Estabelecimento(std::string estoque_loja) :
  estoque(200), quantidade_produtos(0), produtos(nullptr), lucro(0), numero_vendas(0), numero_clientes(0)
{
  std::string linha;
  std::ifstream arquivo(estoque_loja);
  produtos = new Produto[estoque];
  while(!arquivo.eof()){
    if(quantidade_produtos >= estoque){
      aumentar_estoque();
      continue;
    }
    getline(arquivo, linha);
    if (linha.size() == 0) {
      continue;
    }
    if(linha.at(0) == 'C'){
      continue;
    }
    else {
      std::size_t found = linha.find(",");
        produtos[quantidade_produtos].codigo = set_int2(linha.substr(0,found));
        linha.erase(0, found + 1);

      found = linha.find(",");
        produtos[quantidade_produtos].nome = linha.substr(0,found);
        linha.erase(0, found+1);

      found = linha.find(",");
        produtos[quantidade_produtos].unidade = linha.substr(0,found);
        linha.erase(0, found+1);

      found = linha.find(",");
        produtos[quantidade_produtos].preco = set_double(linha.substr(0,found));
        linha.erase(0, found+1);

      found = linha.find(",");
        produtos[quantidade_produtos].quantidade = set_int(linha);
    }
    quantidade_produtos++;
  }
}

Estabelecimento::~Estabelecimento(void)
{
  delete[] produtos;
}

void Estabelecimento::aumentar_estoque(){
   Produto *produtos2;
   produtos2 = new Produto[estoque*2];
   for(int i = 0; i < estoque; i++){
     produtos2[i] = produtos[i];
   }
   estoque = estoque*2;
   delete[] produtos;
   produtos = produtos2;
}

void Estabelecimento::listar(){
  std::cout << std::endl;
  for(int i = 0; i < estoque; i++){
    if(produtos[i].quantidade > 0){
      std::cout << produtos[i].quantidade << " " << produtos[i].unidade << "(s) de ";
      std::cout << produtos[i].nome << std::endl;
    }
  }
}

int Estabelecimento::venda(int codigo){
  for(int i = 0; i < quantidade_produtos; i++){
    if(codigo == produtos[i].codigo){
      if(produtos[i].quantidade == 0){
        std::cout << "Estoque esgotado :(" << std::endl;
        return 1;
      }
      std::cout << "Venda efetuada :)" << std::endl;
      produtos[i].quantidade--;
      lucro += produtos[i].preco;
      registrar_venda(produtos[i]);
    }
  }
  return 0;
}

void Estabelecimento::registrar_venda(Produto item)
{
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

void Estabelecimento::caixa(){
  Produto item;
  std::ofstream caixa("caixa.csv");
  caixa << "COD,PRODUTO,UNIDADE DE MEDIDA,PREÇO,QUANTIDADE" << std::endl;
  for(int i = 0; i < numero_vendas; i++){
    item = vendas[i];
    caixa << item.codigo << ",";
    caixa << item.nome << ",";
    caixa << item.unidade << ",";
    caixa << "\"R$ " << item.preco << "\",";
    caixa << item.quantidade;
    caixa << std::endl;
  }
  caixa << "Lucro total: " << lucro << std::endl;
  caixa.close();
}

void Estabelecimento::reabastecerEstoque(int codigo, int quantidade) {
  for (size_t i = 0; i < produtos.getSize(); i++) {
    if (produtos.at(i)->codigo == codigo) {
      if (fornecedor.repassaProdutos(produtos.at(i)->nome, quantidade)) {
        produtos.at(i)->quantidade += quantidade;
      }
    }
  }
}

void Estabelecimento::atualizar_estoque(){
  Produto item;
  std::ofstream estoque_novo("estoque.csv");
  estoque_novo << "COD,PRODUTO,UNIDADE DE MEDIDA,PREÇO,QUANTIDADE" << std::endl;
  for(int i = 0; i < quantidade_produtos; i++){
    item = produtos[i];
    if(item.quantidade > 0){
      estoque_novo << item.codigo << ",";
      estoque_novo << item.nome << ",";
      estoque_novo << item.unidade << ",";
      estoque_novo << "\"R$ " << item.preco << "\",";
      estoque_novo << item.quantidade;
      estoque_novo << std::endl;
    }
  }
  estoque_novo.close();
}
