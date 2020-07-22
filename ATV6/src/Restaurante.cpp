#include "Restaurante.h"
#include "Util.h"

Restaurante::Restaurante() : Estabelecimento("menu.csv")
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

Restaurante::Restaurante(std::string menuFilename) : Estabelecimento(menuFilename)
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

Restaurante::~Restaurante()
{
}

void Restaurante::load() {
  std::string linha;
  std::ifstream arquivo(filename);

  if (!arquivo.is_open() || arquivo.fail()) {
    throw std::runtime_error("O arquivo não existe no caminho especificado.");
    return;
  }

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
  std::cout << std::string(27, '_') << " MENU " << std::string(26, '_') << std::endl;
  for(size_t i = 0; i < produtos.getSize(); i++){
    std::cout << produtos.at(i).nome
              << " " << std::string(50- (produtos.at(i).nome.size() + 1), '-') << " "
              << double_to_string(produtos.at(i).preco) << std::endl;
  }
}

void Restaurante::venda(Produto& produto) {
  lucro += produto.preco * produto.quantidade;
  registrar_venda(produto);
  std::cout << "Venda efetuada :)" << std::endl;
}

void Restaurante::caixa(){
  Produto item;
  std::string arquivo_caixa = "restaurante_caixa.csv";
  std::ofstream caixa(arquivo_caixa);
  caixa << "PRODUTO,PREÇO,QUANTIDADE" << std::endl;
  for(size_t i = 0; i < vendas.size(); i++){
    item = vendas[i];
    caixa << item.nome << ",";
    caixa << double_to_string(item.preco) << ",";
    caixa << item.quantidade;
    caixa << std::endl;
  }
  caixa << "Lucro total: " << double_to_string(lucro) << std::endl;
  caixa.close();
}
