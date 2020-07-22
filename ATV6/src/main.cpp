#include "Cliente.h"
#include "NegocioException.h"

#include <limits>

int main(int argc, char *argv[]) {
  char comm, aux = '1';
  int n_cliente_restaurante = 0, n_cliente_supermercado = 0;
  while (true) {
    std::cout << "1) Supermercado" << std::endl;
    std::cout << "2) Restaurante" << std::endl;
    std::cout << "3) Encerrar" << std::endl;

    std::cin >> comm;

    if (comm == '3')
      break;
    if (comm == '1') {
      Supermercado loja;
      while (true) {
        std::cout << "1) Novo Cliente" << std::endl;
        std::cout << "2) Finalizar compras" << std::endl;
        std::cin >> aux;
        ;
        if (aux == '2')
          break;
        if (aux == '1') {
          Cliente<Supermercado> cliente(n_cliente_supermercado, &loja);
          while (true) {
            menu_supermercado();
            std::cout << comm << std::endl;
            std::cin >> comm;
            if (comm == '6') {
              limpar_registro(n_cliente_supermercado, "supermercado");
              cliente.registro("supermercado");
              n_cliente_supermercado++;
              break;
            }
            else if (comm == '1')
              cliente.adicionar_saldo();
            else if (comm == '2')
              loja.listar();
            else if (comm == '3')
              cliente.ver_sacola();
            else if (comm == '4')
              cliente.compra();
            else if (comm == '5')
              loja.reabastecerEstoque();
            else
              std::cout << "Comando Invalido!" << std::endl;
          }
        }
        else
          std::cout << "Comando invalido!" << std::endl;
      }
      loja.caixa();
      loja.atualizarEstoque();
    }
    if (comm == '2') {
      Restaurante loja;
      while (true) {
        std::cout << "1) Novo Cliente" << std::endl;
        std::cout << "2) Finalizar" << std::endl;
        std::cin >> aux;

        if (aux == '2')
          break;
        if (aux == '1') {
          Cliente<Restaurante> cliente(n_cliente_restaurante, &loja);
          while (true) {

            menu_restaurante();
            
            std::cin >> comm;
            
            if (comm == '5') {
              limpar_registro(n_cliente_restaurante, "restaurante");
              cliente.registro("restaurante");
              n_cliente_restaurante++;
              break;
            }
            else if (comm == '1')
              cliente.adicionar_saldo();
            else if (comm == '2')
              loja.listar();
            else if (comm == '3')
              cliente.ver_sacola();
            else if (comm == '4')
              cliente.compra();
            else
              std::cout << "Comando Invalido!" << std::endl;
          }
        }
        else
          std::cout << "Comando invalido!" << std::endl;
      }
      loja.caixa();
    } else {
      std::cout << "\nComando invalido!\n" << std::endl;
    }
  }
  return 0;
}
