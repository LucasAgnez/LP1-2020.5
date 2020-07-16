#include "Fornecedor.h"
#include "VectorSupermercado.h"
#include "Produto.h"
#include "Util.h"

#include <string>
#include <sstream>
#include <fstream>


Fornecedor::Fornecedor()
{
  this->load();
}

Fornecedor::~Fornecedor()
{
  this->update();
}

bool repassaProdutos(std::string produto, int quantidade) {
return true;
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
