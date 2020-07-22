#include "Util.h"
#include <sstream>
#include <fstream>

void menu_supermercado(){
  std::cout << std::endl;
  std::cout << "Comandos:" << std::endl;
  std::cout << "  1) Adicionar saldo ao cliente atual" << std::endl;
  std::cout << "  2) Listar produtos da loja" << std::endl;
  std::cout << "  3) Ver sacola do cliente atual" << std::endl;
  std::cout << "  4) Comprar item" << std::endl;
  std::cout << "  5) Reabastecer estoque" << std::endl;
  std::cout << "  0) Encerra compras do cliente" << std::endl << std::endl;
}

void menu_restaurante(){
  std::cout << std::endl;
  std::cout << "Comandos:" << std::endl;
  std::cout << "  1) Adicionar saldo ao cliente atual" << std::endl;
  std::cout << "  2) Listar produtos da loja" << std::endl;
  std::cout << "  3) Ver sacola do cliente atual" << std::endl;
  std::cout << "  4) Comprar item" << std::endl;
  std::cout << "  0) Encerra compras do cliente" << std::endl << std::endl;

}
double set_double(std::string prec){
  std::stringstream stream(prec);
  char discard;
  double preco;
  stream >> discard;
  stream >> discard;
  stream >> preco;
  return preco;
}

int set_int(std::string cod){
  std::stringstream stream(cod);
  int codigo;
  stream >> codigo;
  return codigo;
}

std::string double_to_string(double d) {
  std::stringstream stream;
  stream << "R$ " << d;

  std::string value_s = stream.str();

  size_t pos = value_s.find(".");

  if (pos == std::string::npos) {
    value_s.replace(value_s.length(), 0, ".00");
    return value_s;
  }

  // Retira-se 2 do tamanho caso comAspas = true (aumenta o tamanho da string)
  if (value_s.length()-1 - pos < 2) {
    value_s.replace(value_s.length(), 0, "0");
  }

  return value_s;
}

void limpar_registro(int n, std::string tipo){
  n += 1;
  std::string nome_cliente = "cliente_" + tipo + "_";
  std::string extensao = ".txt";
  std::stringstream stream;
  stream << nome_cliente;
  stream << n;
  stream << extensao;
  std::string nome_arquivo = stream.str();
  std::ofstream arquivo(nome_arquivo);
  arquivo.close();
}
