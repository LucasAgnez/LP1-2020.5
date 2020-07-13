#include "Funcionario.h"


Funcionario::Funcionario()
{
}

Funcionario::Funcionario(std::string nome, std::string departamento, double salario, std::string data_admissao)
  : nome(nome), departamento(departamento), salario(salario), data_admissao(data_admissao)
{
}

std::string Funcionario::get_nome() {
  return nome;
}

void Funcionario::set_nome(std::string n) {
  nome = n;
}

std::string Funcionario::get_departamento() {
  return departamento;
}

void Funcionario::set_departamento(std::string d) {
  departamento = d;
}

double Funcionario::get_salario() {
  return salario;
}

void Funcionario::set_salario(double s) {
  salario = s;
}

std::string Funcionario::get_data_admissao() {
  return data_admissao;
}

void Funcionario::set_data_admissao(std::string d) {
  data_admissao = d;
}
