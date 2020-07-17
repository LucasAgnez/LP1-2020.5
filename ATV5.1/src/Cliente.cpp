#include "Cliente.h"

Cliente::Cliente() : loja(), saldo(100), tamanho_sacola(0), n_cliente(0)
{
}

Cliente::Cliente(int n_client,Estabelecimento* Loja) : loja(), saldo (100), tamanho_sacola(0)
{
  this->n_cliente = n_client;
  this->loja = Loja;
}

void Cliente::compra(){
  std::cout << "Digite o nome do produto que voce quer comprar" << std::endl;
  std::string produto;
  std::cin >> produto;
  for(int i = 0; i < loja->produtos.getSize(); i++){
    if(loja->produtos.at(i).nome == produto){
      compra(produto, loja->produtos.at(i).preco);
      return;
    }
  }
  std::cout << "Produto nao encontrado!" << std::endl;
  std::cout << "verifique a escrita!" << std::endl;
}

void Cliente::compra(std::string produto, double preco){
  Produto item;
  for(int i = 0; i < loja->produtos.getSize(); i++){
    if(produto == loja->produtos.at(i).nome){
      item = loja->produtos.at(i);
      break;
    }
  }
  if(preco > saldo){
    std::cout << "saldo insuficiente" << std::endl;
    return;
  }
  if(!(loja->venda(item.codigo)))
  {
    saldo -= item.preco;
    sacola.push(item);
    tamanho_sacola++;
    return;
  }
}

void Cliente::ver_sacola(){
  for (int i = 0; i < tamanho_sacola; i++){
      std::cout << sacola.at(i).nome << std::endl;
  }
}

void Cliente::registro(){
  n_cliente += 1;
  std::string nome_cliente = "cliente_";
  std::string extensao = ".txt";
  std::stringstream stream;
  stream << nome_cliente;
  stream << n_cliente;
  stream << extensao;
  std::string nome_arquivo = stream.str();
  std::ofstream arquivo(nome_arquivo, std::ios::app);
  for (int i = 0; i < tamanho_sacola; i++){
      arquivo << sacola.at(i).nome << " - R$ " << sacola.at(i).preco << std::endl;
  }
  arquivo.close();
}

void Cliente::adicionar_saldo(){
  std::cout << "Quanto adicinar?" << std::endl;
  double dinheiro;
  std::cin >> dinheiro;
  this->saldo += dinheiro;
}
