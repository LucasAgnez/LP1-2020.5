#include "../include/Fornecedor.h"
#include "../include/VectorSupermercado.h"
#include "../include/Produtos.h"
#include "../include/App.h"

#include <string>
#include <sstream>
#include <fstream>


Fornecedor::Fornecedor()
{
  load();
}

Fornecedor::~Fornecedor()
{
  update();
}

bool repassaProdutos(std::string produto, int quantidade) {
return true;
}

void Fornecedor::load()
{
  std::ifstream file("fornecedor.csv");
  if (!file.is_open() || file.fail()) {
    std::cerr << "Arquivo inacessivel!" << std::endl;
    return;
  }
  std::string line;
  while (!file.eof()) {
    Produto produto;
    std::getline(file, line);

    // Pula para a próxima linha caso a linha seja o Cabeçalho
    if (line == "PRODUTO,QUANTIDADE") {
      continue;
    }

    std::string delimiter = ",";
    size_t pos = 0;
    std::stringstream stream;
    pos = line.find(delimiter);
    produto.nome = line.substr(0,pos);
    line.erase(0, pos+1);
    produto.quantidade = set_int2(line);
   // produtos.push(produto);
    quantidade_produtos++;
  }

  file.close();
}

void Fornecedor::listar()
{
  std::cout << "PRODUTOS [QUANTIDADE]" << std::endl;
  for(int i = 0; i < quantidade_produtos; i++){
   // std::cout << produtos.at(i)->nome << " [" << produtos.at(i)->quantidade << "]" << std::endl;
  }
}

void Fornecedor::update()
{
}
