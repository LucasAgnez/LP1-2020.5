#ifndef W5_ESTABELECIMENTO_H
#define W5_ESTABELECIMENTO_H

#include "Estabelecimento.h"
#include "Produtos.h"
#include "App.h"

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

class Estabelecimento{
  public:
    Estabelecimento();
    Estabelecimento(std::string estoque_loja);
    ~Estabelecimento();
    int estoque;
    int quantidade_produtos;
    Produto* produtos;
    double lucro;
    std::vector<Produto> vendas;
    int numero_vendas;
    int numero_clientes;

    void listar();
    int venda(int codigo);
    void registrar_venda(Produto item);
    void caixa();
    void atualizar_estoque();

    void aumentar_estoque();
};


#endif
