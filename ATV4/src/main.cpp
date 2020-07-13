#include "Cliente.h"



int main(int argc, char* argv[]){
  int comm = 10, n_cliente = 0, aux = 1;
  Estabelecimento loja("estoque.csv");
  while(true){
    std::cout << "1) Novo Cliente" << std::endl;
    std::cout << "0) Finalizar" << std::endl;
    std::cin >> aux;;
    if (aux == 0)
      break;
    if(aux == 1){
      Cliente cliente(n_cliente, &loja);
      while(true){
        menu();
        std::cin >> comm;
        if(comm == 0){
          limpar_registro(n_cliente);
          cliente.registro();
          n_cliente++;
          break;
        } else if(comm == 1)
          cliente.adicionar_saldo();
        else if(comm == 2)
          loja.listar();
        else if(comm == 3)
          cliente.ver_sacola();
        else if(comm == 4)
          cliente.compra();
        else
          std::cout << "Comando Invalido!" << std::endl;
      }
    }
    else
      std::cout << "Comando invalido!" << std::endl;
  }
  loja.caixa();
  loja.atualizar_estoque();
  return 0;
}
