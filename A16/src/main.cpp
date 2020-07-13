#include "Empresa.h"
#include "Funcionario.h"

#include <iostream>


int main(int argc, char const *argv[])
{
    Empresa empresa("Empresa X", "12.345.678/0000-55");
    int aux = 1, i = 0;
    while (true) {
      std::cout << "0) Encerrar" << std::endl;
      std::cout << "1) Adicionar Funcionario" << std::endl;
      std::cin >> aux;
      if(aux == 0)
        break;
      if(aux == 1){
        i++;
        empresa.set_n_funcionarios(i);
        std::string nome;
        std::string departamento;
        double salario;
        std::string data_admissao;

        std::cout << "Nome do " << i << "º funcionário? ";
        std::cin.ignore();
        std::getline(std::cin, nome);

        std::cout << "Departamento do " << i << "º funcionário? ";
        std::getline(std::cin, departamento);

        std::cout << "Salario do " << i << "º funcionário? ";
        std::cin >> salario;

        std::cout << "Data de admissão do " << i << "º funcionário? " << std::endl;
        std::cin.ignore();
        std::getline(std::cin, data_admissao);

        Funcionario funcionario(nome, departamento, salario, data_admissao);
        empresa.get_funcionarios().push_back(funcionario);
      }
   }

  if(i == 0)
    return 0;
  std::cout << "Qual departamento deseja implementar o aumento de 10%? ";
  std::string departamento;
  std::cin.ignore();
  std::getline(std::cin, departamento);

  empresa.aumenta_salario(departamento, 1.10);

  empresa.listar_funcionarios();

  return 0;
}


