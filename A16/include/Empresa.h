#ifndef W5_EMPRESA_H
#define W5_EMPRESA_H

#include "Empresa.h"
#include "Funcionario.h"

#include <string>
#include <vector>
#include <iostream>

class Empresa
{
private:
  std::string nome;
  std::string cnpj;
  std::vector<Funcionario> funcionarios;
  int n_funcionarios;

public:
  Empresa();
  Empresa(std::string nome, std::string cnpj);

  std::string get_nome();
  void set_nome(std::string n);
  std::string get_cnpj();
  void set_cnpj(std::string c);
  std::vector<Funcionario>& get_funcionarios();
  void set_funcionarios(std::vector<Funcionario> f);
  void aumenta_salario(std::string departamento, double aumento);
  void set_n_funcionarios(int n);
  void listar_funcionarios();
};

#endif
