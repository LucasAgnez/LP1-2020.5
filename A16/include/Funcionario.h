#ifndef W5_FUNCIONARIO_H
#define W5_FUNCIONARIO_H

#include "Funcionario.h"

#include <string>

class Funcionario
{
private:
  std::string nome;
  std::string departamento;
  double salario;
  std::string data_admissao;

public:
  Funcionario();
  Funcionario(std::string nome, std::string departamento, double salario, std::string data_admissao);

  std::string get_nome();
  void set_nome(std::string n);
  std::string get_departamento();
  void set_departamento(std::string d);
  double get_salario();
  void set_salario(double s);
  std::string get_data_admissao();
  void set_data_admissao(std::string d);

  };

#endif
