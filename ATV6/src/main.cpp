#include "Cliente.h"

int main(int argc, char* argv[]){
   int comm = 10, n_cliente_restaurante = 0, n_cliente_supermercado = 0, aux = 1;
   while(true){
     std::cout << "1) Supermercado" << std::endl;
     std::cout << "2) Restaurante" << std::endl;
     std::cout << "0) Encerrar" << std::endl;
     std::cin >> comm;
     if(comm == 0)
       break;
     if(comm == 1){
       Supermercado loja;
       while(true){
         std::cout << "1) Novo Cliente" << std::endl;
         std::cout << "0) Finalizar compras" << std::endl;
         std::cin >> aux;;
         if (aux == 0)
           break;
         if(aux == 1){
           Cliente cliente(n_cliente_supermercado, &loja);
           while(true){
             menu_supermercado();
             std::cin >> comm;
             if(comm == 0){
               limpar_registro(n_cliente_supermercado);
               cliente.registro("supermercado");
               n_cliente_supermercado++;
               break;
             } else if(comm == 1)
               cliente.adicionar_saldo();
             else if(comm == 2)
               loja.listar();
             else if(comm == 3)
               cliente.ver_sacola();
             else if(comm == 4)
               cliente.compra();
             else if(comm == 5)
               loja.reabastecerEstoque();
             else
               std::cout << "Comando Invalido!" << std::endl;
           }
         }
         else
           std::cout << "Comando invalido!" << std::endl;
       }
       loja.caixa("supermercado");
       loja.atualizarEstoque();
     }
     if(comm == 2){
       Restaurante loja;
       while(true){
         std::cout << "1) Novo Cliente" << std::endl;
         std::cout << "0) Finalizar" << std::endl;
         std::cin >> aux;;
         if (aux == 0)
           break;
         if(aux == 1){
           Cliente cliente(n_cliente_restaurante, &loja);
           while(true){
             menu_restaurante();
             std::cin >> comm;
             if(comm == 0){
               limpar_registro(n_cliente_restaurante);
               cliente.registro("restaurante");
               n_cliente_restaurante++;
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
       loja.caixa("restaurante");
     }
   }
   return 0;
}
