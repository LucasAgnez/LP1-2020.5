#include "Restaurante.h"

Restaurante::Restaurante() : Estabelecimento("menu.csv")
{
  load();
}

Restaurante::Restaurante(std::string menuFilename) : Estabelecimento(menuFilename)
{
  load();
}

Restaurante::~Restaurante()
{  
}

void Restaurante::load() {
  std::string linha;
  std::ifstream arquivo(filename);
  while(!arquivo.eof()){
    getline(arquivo, linha);

    // Se a linha for vazia ou o primeiro caracter for 'I'(Cabeçalho) pula para a próxima iteração
    if (linha.size() == 0 || linha.at(0) == 'I') {
      continue;
    }

    Produto p;
    std::size_t found;

    found = linha.find(",");
    p.nome = linha.substr(0,found);
    linha.erase(0, found+1);

    found = linha.find(",");
    p.preco = set_double(linha.substr(0,found));
    linha.erase(0, found+1);

    produtos.push(p);
  }
}

void Restaurante::listar() {
  std::cout << std::endl;
  std::cout << "_________ MENU _________" <<std::endl;
  for(int i = 0; i < produtos.getSize(); i++){
    std::cout << produtos.at(i).nome 
              << " " << std::string(45-produtos.at(i).nome.size(), '-') << " " 
              << produtos.at(i).preco << std::endl;
  }
}

int Restaurante::venda(int codigo) {
  for(int i = 0; i < produtos.getSize(); i++){
    if(codigo == produtos.at(i).codigo){
      std::cout << "Venda efetuada :)" << std::endl;
      produtos.at(i).quantidade--;
      lucro += produtos.at(i).preco;
      registrar_venda(produtos.at(i));
    }
  }
  return 0;
}