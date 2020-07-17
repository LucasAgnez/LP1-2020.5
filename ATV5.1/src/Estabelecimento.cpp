#include "Estabelecimento.h"
#include "Fornecedor.h"


Estabelecimento::Estabelecimento() :
  estoque(200), quantidade_produtos(0), lucro(0), numero_vendas(0), numero_clientes(0)
{
  std::string linha;
  std::ifstream arquivo("estoque.csv");
  while(!arquivo.eof()){
    getline(arquivo, linha);
    if (linha.size() == 0) {
      continue;
    }
    if(linha.at(0) == 'C'){
      continue;
    }

    Produto p;

    std::size_t found = linha.find(",");
    p.codigo = set_int2(linha.substr(0,found));
    linha.erase(0, found + 1);

    found = linha.find(",");
    p.nome = linha.substr(0,found);
    linha.erase(0, found+1);

    found = linha.find(",");
    p.unidade = linha.substr(0,found);
    linha.erase(0, found+1);

    found = linha.find(",");
    p.preco = set_double(linha.substr(0,found));
    linha.erase(0, found+1);

    found = linha.find(",");
    p.quantidade = set_int(linha);

    produtos.push(p);

    quantidade_produtos++;
  }
}

Estabelecimento::Estabelecimento(std::string estoque_loja) :
  estoque(200), quantidade_produtos(0), lucro(0), numero_vendas(0), numero_clientes(0)
{
  std::string linha;
  std::ifstream arquivo(estoque_loja);
  while(!arquivo.eof()){
    getline(arquivo, linha);
    if (linha.size() == 0) {
      continue;
    }
    if(linha.at(0) == 'C'){
      continue;
    }

    Produto p;

    std::size_t found = linha.find(",");
    p.codigo = set_int2(linha.substr(0,found));
    linha.erase(0, found + 1);

    found = linha.find(",");
    p.nome = linha.substr(0,found);
    linha.erase(0, found+1);

    found = linha.find(",");
    p.unidade = linha.substr(0,found);
    linha.erase(0, found+1);

    found = linha.find(",");
    p.preco = set_double(linha.substr(0,found));
    linha.erase(0, found+1);

    found = linha.find(",");
    p.quantidade = set_int(linha);

    produtos.push(p);

    quantidade_produtos++;
  }
}

Estabelecimento::~Estabelecimento()
{
}

void Estabelecimento::listar(){
  std::cout << std::endl;
  for(int i = 0; i < produtos.getSize(); i++){
    if(produtos.at(i).quantidade > 0){
      std::cout << produtos.at(i).quantidade << " " << produtos.at(i).unidade << "(s) de ";
      std::cout << produtos.at(i).nome << std::endl;
    }
  }
}

int Estabelecimento::venda(int codigo){
  for(int i = 0; i < quantidade_produtos; i++){
    if(codigo == produtos.at(i).codigo){
      if(produtos.at(i).quantidade == 0){
        std::cout << "Estoque esgotado :(" << std::endl;
        return 1;
      }
      std::cout << "Venda efetuada :)" << std::endl;
      produtos.at(i).quantidade--;
      lucro += produtos.at(i).preco;
      registrar_venda(produtos.at(i));
    }
  }
  return 0;
}

void Estabelecimento::registrar_venda(Produto item) {
  for(int i = 0; i < numero_vendas; i++){
    if(produtos.at(i).codigo == vendas[i].codigo){
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

void Estabelecimento::reabastecerEstoque() {
  std::cout << "Digite o codigo do produto para ser reabastecido:";
  int codigo;
  std::cin >> codigo;
  std::cout << "Digite a quantidade a ser reabastecida:";
  int quantidade;
  std::cin >> quantidade;

  for (size_t i = 0; i < produtos.getSize(); i++) {
    if (produtos.at(i).codigo == codigo && fornecedor.repassaProdutos(produtos.at(i).nome, quantidade)) {
      produtos.at(i).quantidade += quantidade;
      return;
    }
  }
  std::cout << "O fornecdor não possue " << quantidade << " unidade(s) disponíveis.";
}

void Estabelecimento::atualizar_estoque(){
  std::ofstream estoque_novo("estoque.csv");
  estoque_novo << "COD,PRODUTO,UNIDADE DE MEDIDA,PREÇO,QUANTIDADE" << std::endl;
  for(int i = 0; i < quantidade_produtos; i++){
    if(produtos.at(i).quantidade > 0){
      estoque_novo << produtos.at(i).codigo << ",";
      estoque_novo << produtos.at(i).nome << ",";
      estoque_novo << produtos.at(i).unidade << ",";
      estoque_novo << "\"R$ " << produtos.at(i).preco << "\",";
      estoque_novo << produtos.at(i).quantidade;
      estoque_novo << std::endl;
    }
  }
  estoque_novo.close();
}
