#include "Fornecedor.h"
#include "VectorSupermercado.h"
#include "Produto.h"
#include "Util.h"
#include "NegocioException.h"

#include <string>
#include <sstream>
#include <fstream>


Fornecedor::Fornecedor()
{
  try
  {
    load();
  }
  catch(const std::exception& e)
  {
    std::cerr << e.what() << '\n';
    exit(1);
  }
}

Fornecedor::~Fornecedor()
{
  update();
}

void Fornecedor::repassaProdutos(std::string produto, int quantidade) {
  for (size_t i = 0; i < produtos.getSize(); i++) {
    if ((produtos.at(i).nome.compare(produto)) == 0) {
      if (produtos.at(i).quantidade <= quantidade) {
        throw NegocioException("O fornecedor não possui " + std::to_string(quantidade) + " unidade(s) disponíveis.");
      }
      produtos.at(i).quantidade -= quantidade;
    }
  }
}


void Fornecedor::load() {
  std::ifstream file("fornecedor.csv");
  if (!file.is_open() || file.fail()) {
    throw std::runtime_error("O arquivo não existe no caminho especificado.");
    return;
  }

  std::string line;
  while (!file.eof()) {
    Produto produto;
    std::getline(file, line);

    //Caso a linha seja vazia
    if (line.size() == 0) {
      continue;
    }

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
    produto.quantidade = set_int(line);
    produtos.push(produto);
  }

  file.close();
}

void Fornecedor::listar() {
  std::cout << "PRODUTOS [QUANTIDADE]" << std::endl;
  for(size_t i = 0; i < produtos.getSize(); i++){
    std::cout << produtos.at(i).nome << " [" << produtos.at(i).quantidade << "]" << std::endl;
  }
}

void Fornecedor::update() {
  std::ofstream estoque_novo("fornecedor.csv");
  estoque_novo << "PRODUTO,QUANTIDADE" << std::endl;
  for(size_t i = 0; i < produtos.getSize(); i++){
      estoque_novo << produtos.at(i).nome << ",";
      estoque_novo << produtos.at(i).quantidade;
      estoque_novo << std::endl;
  }
  estoque_novo.close();
}
