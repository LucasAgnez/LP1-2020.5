#ifndef W5_CLIENTE_H
#define W5_CLIENTE_H

#include "Cliente.h"
#include "Produto.h"
#include "Estabelecimento.h"
#include "VectorSupermercado.h"

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <fstream>



class Cliente{
  public:
    Cliente();
    Cliente(int n_cliente, Estabelecimento *loja);
    Estabelecimento *loja;
    double saldo;
    VectorSupermercado<Produto> sacola;
    int tamanho_sacola;
    int n_cliente;

    void compra();
    void compra(std::string produto, double preco);
    void ver_sacola();
    void registro();
    void adicionar_saldo();
};


#endif
