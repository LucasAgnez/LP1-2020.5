#include "Supermercado.h"
#include "NegocioException.h"

Supermercado::Supermercado() : Estabelecimento("estoque.csv")
{
  load();
}

Supermercado::Supermercado(std::string estoqueFilename) : Estabelecimento(estoqueFilename)
{
  load();
}

Supermercado::~Supermercado()
{
  atualizarEstoque();
}

void Supermercado::load() {
  std::string linha;
  std::ifstream arquivo(filename);
  while(!arquivo.eof()){
    getline(arquivo, linha);
    if (linha.size() == 0 || linha.at(0) == 'C'){
      continue;
    }

    Produto p;
    std::size_t found = linha.find(",");
    p.codigo = set_int(linha.substr(0,found));
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
  }
}

void Supermercado::listar() {
  std::cout << std::endl;
  std::cout << "Produtos Disponíveis no Estoque:" <<std::endl;
  std::cout << "--------------------------------" <<std::endl;
  for(int i = 0; i < produtos.getSize(); i++){
    if(produtos.at(i).quantidade > 0){
      std::cout << produtos.at(i).quantidade << " " << produtos.at(i).unidade << "(s) de " << produtos.at(i).nome << std::endl;
    }
  }
}

void Supermercado::reabastecerEstoque() {
  char comm;
  std::cout << "1) Listar produtos do fornecedor" << std::endl;
  std::cout << "2) Fazer pedido" << std::endl;
  std::cin >> comm;
  if (comm == '1')
    fornecedor.listar();
  else if(comm == '2'){
    std::cout << "Digite o codigo do produto para ser reabastecido:";
    int codigo;
    std::cin >> codigo;
    std::cout << "Digite a quantidade a ser reabastecida:";
    int quantidade;
    std::cin >> quantidade;

    for (size_t i = 0; i < produtos.getSize(); i++) {
      if (produtos.at(i).codigo == codigo) {

        try {
          fornecedor.repassaProdutos(produtos.at(i).nome, quantidade);
        } catch(NegocioException& e) {
          std::cerr << e.what() << '\n';
        }

        produtos.at(i).quantidade += quantidade;
        return;
      }
    }
  }
  else{
    std::cout << "Comando invalido" << std::endl;
  }
}

void Supermercado::atualizarEstoque() {
  std::ofstream estoque_novo(filename);
  estoque_novo << "COD,PRODUTO,UNIDADE DE MEDIDA,PREÇO,QUANTIDADE" << std::endl;
  for(size_t i = 0; i < produtos.getSize(); i++){
    estoque_novo << produtos.at(i).codigo << ",";
    estoque_novo << produtos.at(i).nome << ",";
    estoque_novo << produtos.at(i).unidade << ",";
    estoque_novo << "R$ " << produtos.at(i).preco << ",";
    estoque_novo << produtos.at(i).quantidade;
    estoque_novo << std::endl;
  }
  estoque_novo.close();
}

void Supermercado::venda(Produto& produto) {
  if(produto.quantidade == 0) {
    throw NegocioException("Estoque esgotado :(");
  }

  produto.quantidade--;
  lucro += produto.preco;
  registrar_venda(produto);
  std::cout << "Venda efetuada :)" << std::endl;
}
