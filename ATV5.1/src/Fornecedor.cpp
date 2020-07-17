#include "Fornecedor.h"
#include "VectorSupermercado.h"
#include "Produto.h"

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

bool Fornecedor::repassaProdutos(std::string produto, int quantidade) {
  for (size_t i = 0; i < produtos.getSize(); i++) {
    if ((produtos.at(i)->nome.compare(produto)) == 0 && produtos.at(i)->quantidade >= quantidade) {
      produtos.at(i)->quantidade -= quantidade;
      return true;
    }
  }
  return false;
}


void Fornecedor::load()
{
  std::ifstream file("fornecedor.csv");
  if (!file.is_open() || file.fail()) {
    throw std::runtime_error("O arquivo não existe no caminho especificado em \"supermercado.config\".");
    return;
  }
  std::string line;
  while (!file.eof()) {
    Produto produto;
    int quantidade;

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
    quantidade = Util::stringToInt(line);
    produtos.push(produto);
  }

  file.close();
}

void Fornecedor::update()
{
}
