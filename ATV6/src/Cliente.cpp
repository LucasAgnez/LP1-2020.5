#include "Cliente.h"
#include "NegocioException.h"
#include "Util.h"

template <class T>
Cliente<T>::Cliente() : loja(), saldo(0), n_cliente(0)
{
}

template <class T>
Cliente<T>::Cliente(int n_client, T* Loja) : loja(), saldo (0)
{
  this->n_cliente = n_client;
  this->loja = Loja;
}

template <class T>
void Cliente<T>::compra(){
  std::cout << "Digite o nome do produto que você quer comprar" << std::endl;
  std::string produto;
  std::cin.ignore();
  std::getline(std::cin, produto);

  try {
    /*Se for um pedido no restaurante, pede a quantidade do produto*/
    if (std::is_same<T, Restaurante>::value) {
      std::cout << "Digite a quantidade do produto que você quer comprar" << std::endl;
      int quantidade;
      std::cin >> quantidade;
      compra(produto, quantidade);
    } else {
      compra(produto);
    }
  } catch(NegocioException& e) {
    std::cerr << e.what() << '\n';
  }
}


template <class T>
void Cliente<T>::compra(std::string produto, int quantidade /*= 1*/) {

  int indexProduto = -1;
  for(size_t i = 0; i < loja->produtos.getSize(); i++){
    if(loja->produtos.at(i).nome == produto){
      indexProduto = (int)i;
    }
  }

  if (indexProduto == -1) {
    throw NegocioException("Produto não encontrado! Verifique a escrita.");
  }

  if(loja->produtos.at(indexProduto).preco * quantidade > saldo) {
    throw NegocioException("Saldo insuficiente. Saldo atual de " + std::to_string(saldo));
    return;
  }

  Produto produtoVendido = loja->produtos.at(indexProduto);
  produtoVendido.quantidade = quantidade;

  try {
    loja->venda(produtoVendido);
  } catch(NegocioException& e) {
    std::cerr << e.what() << '\n';
    return;
  }

  saldo -= loja->produtos.at(indexProduto).preco;

  /*Procura pelo produto comprado na sacola*/
  for (size_t i = 0; i < sacola.getSize(); i++) {
    if (sacola.at(i).nome == loja->produtos.at(indexProduto).nome) {
      /* Caso o produto já exista apenas adiciona a quantidade solicitada ao produto da sacola*/
      sacola.at(i).quantidade += quantidade;
      return;
    }
  }

  /*Caso não tenha comprado nenhuma unidade do produto ainda, cria um novo e defini a quantidade igual a solicitada */
  sacola.push(produtoVendido);
}

template <class T>
void Cliente<T>::ver_sacola(){
  for (size_t i = 0; i < sacola.getSize(); i++){

    if (sacola.at(i).unidade.empty()) {
      std::cout << sacola.at(i).quantidade << " " << sacola.at(i).nome << "(s)"<< std::endl;
      break;
    }

    std::cout << sacola.at(i).quantidade << " " << sacola.at(i).unidade << "(s) de " << sacola.at(i).nome << std::endl;
  }
}

template <class T>
void Cliente<T>::registro(std::string tipo){
  n_cliente += 1;
  std::string nome_cliente = "cliente_" + tipo + "_";
  std::string extensao = ".txt";
  std::stringstream stream;
  stream << nome_cliente;
  stream << n_cliente;
  stream << extensao;
  std::string nome_arquivo = stream.str();
  std::ofstream arquivo(nome_arquivo, std::ios::app);
  for (size_t i = 0; i < sacola.getSize(); i++){
      arquivo << sacola.at(i).nome << " - " << double_to_string(sacola.at(i).preco) << std::endl;
  }
  arquivo.close();
}

template <class T>
void Cliente<T>::adicionar_saldo(){
  std::cout << "Quanto adicinar?" << std::endl;
  double dinheiro;
  std::cin >> dinheiro;
  this->saldo += dinheiro;
}


/**
 * É preciso avisar previamente quais classes serão implementadas no template
 * Caso contrário, occore erro de undefined reference
 */
template class Cliente<Supermercado>;
template class Cliente<Restaurante>;
