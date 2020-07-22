#ifndef W5_CLIENTE_H
#define W5_CLIENTE_H

#include "Cliente.h"
#include "Produto.h"
#include "Estabelecimento.h"
#include "VectorSupermercado.h"
#include "Restaurante.h"
#include "Supermercado.h"

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <fstream>


template <class T>
class Cliente{
  public:
    Cliente();
    Cliente(int n_cliente, T *loja);
    T *loja;
    double saldo;
    VectorSupermercado<Produto> sacola;
    int n_cliente;

    void compra();
    void compra(std::string produto, int quantidade = 1);
    void ver_sacola();
    void registro(std::string tipo);
    void adicionar_saldo();
};


#endif